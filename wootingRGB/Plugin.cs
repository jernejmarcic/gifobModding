using BepInEx;

// Sends info to the wooting RGB bridge python file
using System.Net.Sockets;
using System.Text;

[BepInPlugin("dev.jernej.gifob.wootingRGB", "wootingRGB", "0.1.0")]
public class Plugin : BaseUnityPlugin {
    void Awake() {
        Logger.LogInfo("GIFOB Wooting RGB loaded");
        PlayerHealth.OnPlayerHealthChange += OnHealthChange; // Trigger event when health change detected
        PlayerAttack.OnReload += OnReload; // Triggers event when reload detected
        SceneLoader.OnAfterNewSceneLoaded += OnScene; // Triggers when a new scene has loaded, AKA when you enter a new level
    }
    UdpClient udp = new UdpClient();
    void OnHealthChange(float change) {
           if (change < 0f) { // only triggers if change is negative
                Logger.LogInfo("hit for " + -change);
                // Sends message via lo python program driving the RGB
                byte[] msg = Encoding.ASCII.GetBytes("hit " + -change);
                udp.Send(msg, msg.Length, "127.0.0.1", 6744);
           }
       }
       void OnReload(PlayerAttack attack) {
        Logger.LogInfo("Player relaoded");
        byte[] msg = Encoding.ASCII.GetBytes("reloaded");
        udp.Send(msg, msg.Length, "127.0.0.1", 6744);

       }
       void OnScene(string scene) {
           Logger.LogInfo("scene " + scene);
           string text = "";
           if (scene == "Headquarters") text = "hq";
           // Takes the biomeID so it can be converted into an animation on the keyboard
           if (scene == "Main") text = "biome " + Singleton<BiomeManager>.Instance.GetCurrentBiome().BiomeID;
           if (text == "") return;
           byte[] msg = Encoding.ASCII.GetBytes(text);
           udp.Send(msg, msg.Length, "127.0.0.1", 6744);
       }
}
