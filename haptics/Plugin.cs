using BepInEx;

[BepInPlugin("dev.jernej.gifob.haptics", "haptics", "0.1.0")]
public class Plugin : BaseUnityPlugin {
    void Awake() {
        Logger.LogInfo("GIFOB haptics loaded");
    }
}
