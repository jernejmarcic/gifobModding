// Game is Full of Bugs colour palette, from the developer. {r, g, b}, 0-255.
#pragma once

#include <cstdint>

struct Colour {
	uint8_t r, g, b;
};

// greys and whites
const Colour black      = { 0, 0, 0 };        // #000000
const Colour slateDark  = { 46, 46, 67 };     // #2e2e43
const Colour greyDark   = { 74, 75, 91 };     // #4a4b5b
const Colour grey       = { 112, 123, 137 };  // #707b89
const Colour greyMid    = { 111, 110, 114 };  // #6f6e72
const Colour greyLight  = { 169, 188, 191 };  // #a9bcbf
const Colour greyPale   = { 230, 238, 237 };  // #e6eeed
const Colour offWhite   = { 252, 251, 243 };  // #fcfbf3
const Colour paperWhite = { 253, 253, 245 };  // #fdfdf5
const Colour white      = { 255, 255, 255 };  // #ffffff

// yellows, oranges, browns
const Colour cream        = { 252, 235, 168 };  // #fceba8
const Colour butter       = { 255, 241, 169 };  // #fff1a9
const Colour sand         = { 245, 196, 124 };  // #f5c47c
const Colour gold         = { 235, 184, 91 };   // #ebb85b
const Colour ochre        = { 199, 133, 57 };   // #c78539
const Colour amber        = { 255, 167, 0 };    // #ffa700
const Colour orange       = { 227, 151, 100 };  // #e39764
const Colour orangeBright = { 230, 113, 70 };   // #e67146
const Colour copper       = { 161, 92, 52 };    // #a15c34
const Colour rust         = { 192, 104, 82 };   // #c06852
const Colour brown        = { 118, 64, 50 };    // #764032
const Colour brownDark    = { 64, 46, 43 };     // #402e2b
const Colour khaki        = { 158, 150, 115 };  // #9e9673
const Colour khakiLight   = { 174, 164, 126 };  // #aea47e

// reds and pinks
const Colour brick     = { 183, 65, 50 };    // #b74132
const Colour redBrown  = { 157, 67, 67 };    // #9d4343
const Colour crimson   = { 194, 55, 83 };    // #c23753
const Colour raspberry = { 122, 40, 73 };    // #7a2849
const Colour wine      = { 129, 54, 69 };    // #813645
const Colour pink      = { 230, 122, 132 };  // #e67a84

// purples
const Colour magenta     = { 222, 0, 255 };   // #de00ff
const Colour plum        = { 84, 34, 64 };    // #542240
const Colour plumDark    = { 42, 21, 45 };    // #2a152d
const Colour plumDeep    = { 60, 37, 61 };    // #3c253d
const Colour plumBlack   = { 50, 31, 54 };    // #321f36
const Colour violetDark  = { 58, 27, 64 };    // #3a1b40
const Colour purpleBlack = { 31, 16, 36 };    // #1f1024
const Colour mauveDark   = { 79, 45, 77 };    // #4f2d4d
const Colour mauve       = { 91, 58, 86 };    // #5b3a56
const Colour mauveLight  = { 121, 78, 109 };  // #794e6d
const Colour dusk        = { 83, 70, 100 };   // #534664

// blues
const Colour night       = { 18, 14, 35 };     // #120e23
const Colour indigoBlack = { 21, 17, 39 };     // #151127
const Colour indigoGrey  = { 42, 41, 66 };     // #2a2942
const Colour blueDark    = { 62, 76, 126 };    // #3e4c7e
const Colour blue        = { 73, 95, 148 };    // #495f94
const Colour blueMid     = { 90, 120, 178 };   // #5a78b2
const Colour blueLight   = { 115, 150, 213 };  // #7396d5
const Colour sky         = { 127, 187, 220 };  // #7fbbdc
const Colour cyan        = { 0, 203, 255 };    // #00cbff
const Colour slate       = { 52, 64, 79 };     // #34404f
const Colour slateBlue   = { 64, 89, 103 };    // #405967
const Colour steel       = { 92, 137, 149 };   // #5c8995
const Colour petrol      = { 36, 80, 95 };     // #24505f

// greens and teals
const Colour aqua       = { 170, 238, 234 };  // #aaeeea
const Colour teal       = { 42, 125, 117 };   // #2a7d75
const Colour tealDark   = { 44, 80, 73 };     // #2c5049
const Colour seaGreen   = { 64, 112, 96 };    // #407060
const Colour limeLight  = { 213, 248, 147 };  // #d5f893
const Colour greenLight = { 150, 220, 127 };  // #96dc7f
const Colour mint       = { 109, 186, 121 };  // #6dba79
const Colour green      = { 110, 192, 119 };  // #6ec077
const Colour emerald    = { 52, 156, 88 };    // #349c58
const Colour greenMid   = { 78, 147, 99 };    // #4e9363
const Colour greenDark  = { 60, 108, 84 };    // #3c6c54
const Colour mustard    = { 201, 192, 61 };   // #c9c03d
const Colour olive      = { 126, 148, 50 };   // #7e9432
const Colour oliveDark  = { 86, 100, 46 };    // #56642e
