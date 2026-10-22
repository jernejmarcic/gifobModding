using BepInEx;
using HarmonyLib;
using UnityEngine;

[BepInPlugin("dev.jernej.gifob.mortarMarker", "mortarMarker", "0.1.0")]
public class Plugin : BaseUnityPlugin {
    void Awake() {
        new Harmony("dev.jernej.gifob.mortarMarker").PatchAll();
    }
}

[HarmonyPatch(typeof(BulletBase), nameof(BulletBase.ShootBullet))]
class MortarPatch {
    static void Postfix(BulletBase __instance, BulletShotType ___bulletShotType, int shooterUnitFactionID, Rigidbody2D ___body2D, DamageStats ___myDamageStatsHolder) {
        if (___bulletShotType == BulletShotType.Mortar && shooterUnitFactionID == 0) {
            Vector3 start = __instance.transform.position;
            Vector3 velocity = ___body2D.linearVelocity;
            float flightTime = __instance.MyBaseModule.MortarShotDuration;
            float blastSize = ___myDamageStatsHolder.aoe;
            Vector3 landing = start + velocity * flightTime;
            StaticInstance<IndicatorManager>.Instance.PlaceDangerAoe(landing, blastSize, flightTime);
        }
    }
}
