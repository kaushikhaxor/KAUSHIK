//Hook
void (*orig_LaunchBP)(ASTExtraShootWeaponBulletBase* pObj, float Speed, AActor* InOwningWeapon, AActor* InInstigator, FTransform* InTrans, FTransform* OutTrans);
void hook_LaunchBP(ASTExtraShootWeaponBulletBase* pObj, float Speed, AActor* InOwningWeapon, AActor* InInstigator, FTransform* InTrans, FTransform* OutTrans) {
  
 if (Config.SilentAim.Enable) {
        ASTExtraPlayerCharacter* Target = GetTargetFoBT();
        if (Target) {
            bool triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                auto CurrentWeaponReplicated = pObj->OwningShootWeapon;
                if (CurrentWeaponReplicated) {
                    CurrentWeaponReplicated->ShootMode = EShootWeaponShootMode::SWST_TraceTarget;
                    auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                    if (ShootWeaponComponent) {
                        ASTExtraVehicleBase* CurrentVehicle = Target->CurrentVehicle;
                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        FVector Velocity = CurrentVehicle ? CurrentVehicle->ReplicatedMovement.LinearVelocity : Target->GetVelocity();
                        float timeToTravel = dist / CurrentWeaponReplicated->GetBulletFireSpeedFromEntity();
                        targetAimPos = targetAimPos + (Velocity * timeToTravel);

      FRotator AimRotation = ToRotator1(OutTrans->Translation, targetAimPos);
      OutTrans->Rotation = RotatorToQuat(AimRotation);
                    }
                }
            }
        }
    }
    orig_LaunchBP(pObj, Speed, InOwningWeapon, InInstigator, InTrans, OutTrans);
}

Tools::Hook((void *) (UE4 + 0x7474B6C), (void *)hook_LaunchBP, (void **) &orig_LaunchBP); //BGMI64 3.5

LauncherBp ( Bt )
Fake Damage Fix ( Glitch )

Cr - @Mrkaushikhaxor

⚠️ People Who Share Without Credit Are Sons Of Bitches 😏