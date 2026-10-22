// Im sorry but python is too annoying to write. Got to go back to my comfort language
#include <arpa/inet.h>
#include <sys/socket.h>
#include <chrono>
#include <cstdio>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>
#include <cmath>

extern "C" {
#include <wooting-rgb-sdk.h>
}

#include "palette.h"

Colour dim(Colour c, float t) {
	return { uint8_t(c.r * t), uint8_t(c.g * t), uint8_t(c.b * t) };
}


void fill(Colour colour) {
	// every key the same colour, then send it to the keyboard
	for (uint8_t row = 0; row < 6; row++)
		for (uint8_t col = 0; col < 21; col++)
			wooting_rgb_array_set_single(row, col, colour.r, colour.g, colour.b);
	wooting_rgb_array_update_keyboard();
}

void flash(Colour color, float speed) {
	int frames = speed * 30;
	for (int i = 0; i <= frames; i++) {
		float t = 1 - (float)i / frames;  // 1 at the start, 0 at the end
		fill(dim(color, t));              // fill sends the frame itself
	}
}


void sweep(Colour color, float speed, int width, const std::vector<int>& rows) {
	int frames = speed * 30;  // Draws at 30 FPS
	for (int i = 0; i <= frames; i++) {
		float centre = -width + (21 + 2 * width) * (float)i / frames;
		for (uint8_t row = 0; row < 6; row++) {
			for (uint8_t col = 0; col < 21; col++) {
				bool inRows = std::find(rows.begin(), rows.end(), row) != rows.end();
				bool lit    = inRows && std::abs(col - centre) < width / 2.0f;
				float t     = std::max(0.0f, 1 - std::abs(col - centre) / width);
				if (!inRows) t = 0;
				Colour c = dim(color, t);
				wooting_rgb_array_set_single(row, col, c.r, c.g, c.b);
			}
		}
		wooting_rgb_array_update_keyboard();
	}
	fill(black);  // Back to off
}

int main() {
	if (!wooting_rgb_kbd_connected()) {
		std::puts("no keyboard");
		return 1;
	}
	int udp = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in address{};
	address.sin_family = AF_INET;
	address.sin_port   = htons(6744);
	inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
	bind(udp, (sockaddr*)&address, sizeof address);

	fill(black);
	char buffer[64];
	while (true) {
		ssize_t length = recv(udp, buffer, sizeof buffer - 1, 0);
		if (length <= 0) continue;
		buffer[length] = '\0';
		std::istringstream words(buffer);
		std::string first;
		words >> first;
		std::printf("%s\n", buffer);
		if (first == "hit") {
			flash(crimson, 0.4f);
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
			fill(black);
		} else if (first == "reloaded") {
			sweep(white, 0.77f, 3, { 0, 1, 2, 3, 4, 5 });
		}
	}
}
