/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Prince Kaushik
 */
#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/limits.h>
#include <sys/mman.h>
#include <imgui/imgui.h>
#include "Includes/Includes.h"
#include "Kaushik/Tools.h"
#include "Kaushik/fake_dlfcn.h"
#include "Kaushik/Vector3.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "Kaushik/StrEnc.h"
#include "Kaushik/plthook.h"
#include "Kaushik/Items.h"
#include "Kaushik/fontch.h"
#include "Kaushik/obfuscate.h"
#include "Kaushik/ScanEngine.hpp"
#include "Kaushik/KittyMemory/MemoryPatch.h"
#include "Kaushik/Substrate/And64InlineHook.hpp"
#include "Kaushik/XorStr.h"
#include "Kaushik/json.hpp"
#include "Kaushik/Rect.h"
#include "Kaushik/Iconcpp.h"
#include "Kaushik/Menu.h"
#include "Kaushik/Font.h"
#include "Kaushik/Icon.h"
#include "Kaushik/HUD.h"
#include "Kaushik/HUD2.h"
#include "Kaushik/HUD3.h"
#include "Kaushik/Social.h"
#include "Kaushik/KaushikVoice.h"
using json = nlohmann::json;
#define SLEEP_TIME 1000LL / 60LL
#include "Kaushik/SDK.hpp"
using namespace SDK;
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
json items_data;
#include "Includes/base64/base64.h"
#include "Offset.h"
#include "Includes/settings.h"
#include "Kaushik/Syscalll.h"
#include "Kaushik/Syscall.h"
//#include "Kaushik.h"//Avaliable Only Java
//================= Offline Fix Hook ====================//
#if defined(aarch64)
#include <Kaushik/Substrate/And64InlineHook.hpp>
#else
#include <Kaushik/Substrate/SubstrateHook.h>
#include <Kaushik/Substrate/CydiaSubstrate.h>
#endif
void kaushik(void *offset, void* ptr, void **orig){
#if defined(aarch64)
A64HookFunction(offset, ptr, orig);
#else
MSHookFunction(offset, ptr, orig);
#endif
}
//================ Offline Hook End =====================//
#define IM_PI 3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))

static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
static float isRedV2 = 0.0f, isGreenV2 = 0.01f, isBlueV2 = 0.0f;

float menu[4] = { 0/255.f, 255/255.f, 0/255.f, 1.000f };




using namespace kFox;
#define DefineHook(RET, NAME, ARGS) \
RET(*Orig_##NAME)               \
ARGS;                           \
RET Hook_##NAME ARGS
/*template<typename T>
void Write(uintptr_t addr, T value) {
WriteAddr((void *) addr, &value, sizeof(T));
}
*/
template<typename T>
void Write(uintptr_t addr, T value) {
    Tools::WriteAddr((void *) addr, &value, sizeof(T));
}



bool WriteAddr(void *addr, void *buffer, size_t length) {
unsigned long page_size = sysconf(_SC_PAGESIZE);
unsigned long size = page_size * sizeof(uintptr_t);
return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}



uintptr_t Mrkaushikhaxor;
uintptr_t UE4;
uintptr_t anogs;


char extras[32];
android_app *g_App = 0;
time_t expiredDate = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;

ImFont* Injector;
ImFont* Injector2;
ImFont* Injector3;
ImFont* Social = nullptr;
ImFont* Arabic;
float size_child = 0;
static float SliderFloat = 0;
static int a = 0;

time_t rng = 0;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;
std::map<int, bool> Items;
std::map<int, float *> ItemColors;
std::string g_Token, g_Auth;


std::string EXP = "";
std::string floating ="";


float WideViewRange = 120;
float AimSmooth = 1.0f;
float SetZoom = 10.0f;
float AimDis = 200.0f;
float BtDis = 100.0f;
float FOVSize = 5;
float FOVSizea = 120;
float WeaponScaleChanger = 4.0f;

float HealthSet1;
float HealthSet2;
float HealthSet3;
float HealthSet4;

bool bValid = false;
bool Magic;
bool ggxhitXhitRainBow;
bool SlowMotion;
bool SdkFlash;
bool ActiveAllesp;
bool NEWMENU = true;
bool WideView;
bool Zoom;
bool PlayerDance;
bool SmallCrossRgbCross;
bool FASTPARACHUTE;
bool IpadView;
bool initImGui = false;

bool SkinxShuit;
static int skinxsuit = 0;
int PreviousSuit = 0; // add in offsets includes (top of source).

bool InjectHack = true;
bool InjectUi = false;

enum EEspUI {
UI0 = 0,
UI1 = 1,
UI2 = 2,
UI3 = 3
};



enum EAimBy {
    Distance = 0,
	FOV = 1
};

enum EAimB {
    Bt90 = 0,
	Bt360 = 1
};

enum EAimTarget {
    Head = 0,
    Chest = 1
};

enum EAimTrigger {
    
	None = 0,
	Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};
    struct sOTHER {
        bool FPS;
        bool EXPIRYTIME;
    };


	
struct sConfig {
	bool Bypass;
	bool Nation;
	float Cross;
	bool FPS;
	bool killmessage;
	float Skill;
	float Skill1;
	float Skill3;
	float Skill4;
	float FOVSizea;
	float FOVSize;
	float Skill2;
	float Line;
	float Recc = 1.435;
	bool TELEPORT;
	
    struct sMrkaushikhaxor {
        bool Bypass;
		bool RGB;
		bool LineBelow;
		bool KERO;
		bool Island;
        bool LineMid;
        bool Recc;
        bool LootBoxItems;
        bool Box3D;
        bool Box4Line;
        bool Namee;
        bool keroz;
        bool LineTop;
        bool VehicleFuel;
        bool VehicleHP;
        bool WeaponId;
        bool BoxItems;
		bool ActiveEsp;
		bool MagicBullet;
		bool VehicleDist;
		bool Alert;
		bool Fuel;
		bool Nation;
		bool States;
		bool Dynamic;
        bool Line;
		bool Radar;
		bool RadarDraw2;
		bool Radar1;
		bool Radar2;
		bool Radar3;
		bool Radar4;
		bool Warning;
        bool Box;
        bool Skeleton;
        bool Health;
        bool Grenade;
        bool ShowKnockedHealth;
        bool KEROO3;
        bool Name;
        bool Distance;
        bool TeamID;
        bool NoBot;
        bool LootBox;
        bool Vehicle;
		bool LootItem;
		bool AirDrop;
		bool Plane;
		bool NamePc;
		bool DistancePc;
		bool HealthPC;
		bool TeamIDPc;
		bool Weapon;
		EEspUI EUI;
    };
    sMrkaushikhaxor Mrkaushikhaxor{0};

    struct sAimMenu {
        bool Enable;
        bool Less;
		bool Enable2;
        bool AimBot;
		float Cross;
        float RecZ;
		float RecX;
		float RecY;
		EAimBy AimBy;
	    EAimB  AimB;
        EAimTarget Target;
        EAimTrigger Trigger;
		
		float AimSet = 1.0f;
        bool Pred;
        bool ReCo;
        bool IgnoreKnocked;
        bool VisCheck;
		bool IgnoreBots;
		bool IgnoreBot;
		bool Recc;
        bool headshot;
    };
	sAimMenu SilentAim{0};
	sAimMenu AimBot{0};
	sAimMenu BulletTrack{0};

	struct sMEM
	{
    bool Warning;
    bool Warning1;
	};
	sMEM MEM{0};
	
struct sHighRisk
	{
		bool Shake;
		bool Recoil;
		bool Recoil1;
		bool RGB;
		bool Blacksky;
		bool Instant;
		bool HitEffect;
		bool Wall;
		bool SmallCrossRgbCross;
		bool FlashSdk;
		bool Instantv2;
		bool wall;
		bool WideView;
		bool Bypass = true;
        bool FPSUnlock = true;
        bool TSSBypass = true;
        bool TSSBypass2 = true;
        bool blockspect = true;
		bool CarSpeed;
		bool HS;
		bool Autofire;
		bool SmallAim;
		bool Shoot;
		bool Fly;
		bool Unlock;
		bool NoFog;
		bool RainSnow;
		bool Blood;
		bool UnlockFPS120;
		bool Jump;
		bool NoGravity;
		bool God;
        bool Down;
        bool UP;
        bool RIGHT;
        bool LEFT;
        bool FRONT;
        bool BACK;
	};
	sHighRisk HighRisk{0};




	struct sOTHER {
        bool FPS;
        bool HIDEESP;
        bool EXPIRYTIME;
    };
    sOTHER OTHER{0};
};
sConfig Config{0};


#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};
// ======================================================================== //
UWorld *GEWorld;
int GWorldNum = 0;
TUObjectArray gobjects;
UWorld *GetWorld()
{
    if(GWorldNum == 0) {
        gobjects = UObject::GUObjectArray->ObjObjects;
        for (int i=0; i< gobjects.Num(); i++)
            if (auto obj = gobjects.GetByIndex(i)) {
                if(obj->IsA(UEngine::StaticClass())) {
                    auto GEngine = (UEngine *) obj;
                    if(GEngine) {
                        auto ViewPort = GEngine->GameViewport;
                        if (ViewPort)
                        {
                            GEWorld = ViewPort->World;
                            GWorldNum = i;
                            return ViewPort->World;
                        }
                    }
                }
            }
    }else {
        auto GEngine = (UEngine *) (gobjects.GetByIndex(GWorldNum));
        if(GEngine) {
            auto ViewPort = GEngine->GameViewport;
            if(ViewPort) {
                GEWorld = ViewPort->World;
                return ViewPort->World;
            }
        }
    }
    return 0;
}

TNameEntryArray *GetGNames() {
return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();}
std::vector<AActor *> getActors() {
auto World = GetWorld();
if (!World)
return std::vector<AActor *>();
auto PersistentLevel = World->PersistentLevel;
if (!PersistentLevel)
return std::vector<AActor *>();
struct GovnoArray {
uintptr_t base;
int32_t count;
int32_t max;};
static thread_local GovnoArray Actors{};
Actors = *(((GovnoArray*(*)(uintptr_t))(UE4 + GetActorArray))(reinterpret_cast<uintptr_t>(PersistentLevel)));
if (Actors.count <= 0) {return {};}
std::vector<AActor *> actors;
for (int i = 0; i < Actors.count; i++) {
auto Actor = *(uintptr_t *) (Actors.base + (i * sizeof(uintptr_t)));
if (Actor) {
actors.push_back(reinterpret_cast<AActor *const>(Actor));
}}return actors;}


template<class T>
void GetAllActors(std::vector<T *> &Actors) {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
    auto GWorld = GetWorld();
    if (GWorld) {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++) {
            Actors.push_back((T *) Actors2[i]);
        }
    }
}


struct sRegion {uintptr_t start, end;};
std::vector<sRegion> trapRegions;
bool isObjectInvalid(UObject *obj) {
if (!Tools::IsPtrValid(obj)) {return true;}
if (!Tools::IsPtrValid(obj->ClassPrivate)) {return true;}
if (obj->InternalIndex <= 0) {return true;}
if (obj->NamePrivate.ComparisonIndex <= 0) {return true;}
if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {return true;}
if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
return true;}return false;}
const char *getObjectPath(UObject *Object) {
std::string s;
for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
if (!s.empty())
s += ".";
s += super->GetName();}return s.c_str();}




int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}

FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);

    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}


#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)

/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Prince Kaushik
 */
bool isInsideFOVs(int x, int y) {
    if (!Config.AimBot.Enable)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.AimBot.Cross*0.5f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}


auto GetTargetForAimBot() {
   ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto Actors = getActors();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
	if (localPlayer)
	{
		for (auto Actor : Actors)
		{
			if (isObjectInvalid(Actor))
				continue;
			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
			{
				auto Player = (ASTExtraPlayerCharacter *)Actor;
				
				
				   float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                if (Distance > 180.0f)
                    continue;
				
				
				
				if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
					
					
					
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;
					
					
                              if (Config.AimBot.IgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }


                        if (Config.AimBot.VisCheck) {
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }
                        if (Config.AimBot.IgnoreBot) {
                            if (Player->bEnsure)
                                continue;
                        }

                        auto Root = Player->GetBonePos("Root", {});
				auto Head = Player->GetBonePos("Head", {});
				FVector2D RootSc, HeadSc;
				if (W2S(Root, &RootSc) && W2S(Head, &HeadSc))
				{
					float height = abs(HeadSc.Y - RootSc.Y);
					float width = height * 0.20f;

					FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
					{
						FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
						FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
						
						
                                if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {

                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                              }
                            }
                        }
                    
                
            }
        }
    }

    return result;
}


auto GetTargetByPussy()
{
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
auto Actors = getActors();

    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;
    FVector ViewPosY{0, 0, 0};
    if (localPlayer)
    {
        ViewPosY = localPlayer->GetBonePos("Head", {});
        ViewPosY.Z += -15.0f;
    }

    
    if (localPlayer)
    {
        for (int i = 0; i < Actors.size(); i++)
        {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
            {

                auto Player = (ASTExtraPlayerCharacter *)Actor;
                float Dist = localPlayer->GetDistanceTo(Player) / 100.0f;

                if (Dist > BtDis)//if (Dist > 500.0f)
                    continue;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Player->bHidden)
                    continue;

                if (Config.SilentAim.IgnoreKnocked)
                {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.SilentAim.VisCheck){
                
                if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }

                if (Config.SilentAim.IgnoreBot)
                {
                  if (Player->bEnsure)
                        continue;
                }
                
                 auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                            }
                        }
                    }
                }
            }
        }
    return result;
}

// ================================================================================================================================ //


void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;
bool qwcifqvs86y8fify = false;
void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1){
if (qwcifqvs86y8fify) {
 qwcifqvs86y8fify = false;
  g_LocalController->bIsPressingFireBtn = false;
thiz->OwnerShootWeapon->StopFire(EFreshWeaponStateType::FreshWeaponStateType_Idle);
}
if (Config.SilentAim.Enable){
        ASTExtraPlayerCharacter *Target = GetTargetByPussy();
        if (Target) {
            FVector location = g_LocalController->PlayerCameraManager->CameraCache.POV.Location;         
            FVector targetAimPos = Target->GetBonePos("Head", {0, 0, 0});
            
            targetAimPos.Z -= -Config.SilentAim.AimSet;
            FRotator sex = ToRotator(start, targetAimPos);
            return orig_shoot_event(thiz, targetAimPos, sex, weapon, unk1);
        }
    }
return orig_shoot_event(thiz, start, rot, weapon, unk1);
}

void (*Orig_Shoot_Event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2, float a6, float a7, float a8) = 0;
void Hook_Shoot_Event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1, float a6, float a7, float a8)
{
    if (Config.BulletTrack.Enable){
        ASTExtraPlayerCharacter *Target = GetTargetByPussy();
        if (Target)
        {
            FVector targetAimPos = Target->GetBonePos("Head", {0, 0, 0});
            
            
            FRotator sex = ToRotator(start, targetAimPos);

            return Orig_Shoot_Event(thiz, targetAimPos, sex, weapon, unk1, a6, a7, a8);
        }
    }
    return Orig_Shoot_Event(thiz, start, rot, weapon, unk1, a6, a7, a8);
}


void RenderESPPRIVATE(AHUD *HUD, int ScreenWidth, int ScreenHeight) {
    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localPlayerController = 0;

    UCanvas *Canvas = HUD->Canvas;
    if (Canvas) {
        UGameplayStatics *gGameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
        auto GWorld = GetWorld();
        if (GWorld) {
            UNetDriver *NetDriver = GWorld->NetDriver;
            if (NetDriver) {
                UNetConnection *ServerConnection = NetDriver->ServerConnection;
                if (ServerConnection) {
                    localPlayerController = (ASTExtraPlayerController *) ServerConnection->PlayerController;
                }
            }

            if (localPlayerController) {
                std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                GetAllActors(PlayerCharacter);
                for (auto actor = PlayerCharacter.begin();
                        actor != PlayerCharacter.end(); actor++) {
                    auto Actor = *actor;

                    if (Actor->PlayerKey ==
                            ((ASTExtraPlayerController *) localPlayerController)->PlayerKey) {
                        localPlayer = Actor;
                        break;
                    }
                }


                {
                            if (localPlayer) {
                        auto infinity = std::numeric_limits<float>::infinity();
                        auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                        if (localPlayer->PartHitComponent) {
                            auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                            for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                                ConfigCollisionDistSqAngles[j].Angle = 180.0f;
                            }
                            localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                        }
                    }
                }
            }
            g_LocalPlayer = localPlayer;
            g_LocalController = localPlayerController;
        }
    }
}


class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 2;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

FPSCounter fps;


void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, float rounding, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}

void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
 if (forward.X == 0.f && forward.Y == 0.f) {
  angles.X = forward.Z > 0.f ? -90.f : 90.f;
  angles.Y = 0.f;
 } else {
  angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
  angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
 }
 angles.Z = 0.f;
}

void RotateTriangle(std::array<Vector3, 3> & points, float rotation) {
 const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
 for (auto & point : points) {
  point = point - points_center;
  const auto temp_x = point.X;
  const auto temp_y = point.Y;
  const auto theta = DEG2RAD(rotation);
  const auto c = cosf(theta);
  const auto s = sinf(theta);
  point.X = temp_x * c - temp_y * s;
  point.Y = temp_x * s + temp_y * c;
  point = point + points_center;
 }
}

FVector2D pushToScreenBorder(FVector2D Pos, FVector2D screen, int borders, int offset) {
	int x = (int)Pos.X;
	int y = (int)Pos.Y;
	if ((borders & 1) == 1) {
		y = 0 - offset;
	}
	if ((borders & 2) == 2) {
		x = (int)screen.X + offset;
	}
	if ((borders & 4) == 4) {
		y = (int)screen.Y + offset;
	}
	if ((borders & 8) == 8) {
		x = 0 - offset;
	}
	return FVector2D(x, y);
}

int isOutsideSafezone(FVector2D pos, FVector2D screen) {
	FVector2D mSafezoneTopLeft(screen.X * 0.04f, screen.Y * 0.04f);
	FVector2D mSafezoneBottomRight(screen.X * 0.96f, screen.Y * 0.96f);
	int result = 0;
	if (pos.Y < mSafezoneTopLeft.Y) {
		result |= 1;
	}
	if (pos.X > mSafezoneBottomRight.X) {
		result |= 2;
	}
	if (pos.Y > mSafezoneBottomRight.Y) {
		result |= 4;
	}
	if (pos.X < mSafezoneTopLeft.X) {
		result |= 8;
	}
	return result;
}

void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color) {
    int iw = w / 4;
    int ih = h / 4;
    // top
    draw->AddRect(ImVec2(x, y),ImVec2(x + iw, y), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y),ImVec2(x + w, y), color, thicc);
    draw->AddRect(ImVec2(x, y),ImVec2(x, y + ih), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y),ImVec2(x + w - 1, y + ih), color, thicc);;
    // bottom
    draw->AddRect(ImVec2(x, y + h),ImVec2(x + iw, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y + h),ImVec2(x + w, y + h), color, thicc);
    draw->AddRect(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thicc);
}

void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}

void DrawFilledRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}

void DrawRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}
bool W2S2(FVector worldPos, FVector2D *screenPos) {
    return g_LocalController->ProjectWorldLocationToScreen(worldPos, true, screenPos);
}

void Line(ImDrawList *draw,FVector2D origin, FVector2D dest, ImColor color)
{
   draw->AddLine({origin.X, origin.Y},{dest.X, dest.Y},color, 2.0f);
}


void Box3D1(ImDrawList *draw, FVector origin, FVector extends, ImColor col) {
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;
    
    
 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;

    FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    if (W2S2(one, &s1) && W2S2(two, &s2) && W2S2(tree, &s3) && W2S2(four, &s4) &&
    W2S2(five, &s5) && W2S2(six, &s6) && W2S2(seven, &s7) && W2S2(eight, &s8))
    {
        
    Line(draw,s1, s2, col);
    Line(draw,s2, s3, col);
    Line(draw,s3, s4, col);
    Line(draw,s4, s1, col);
 
    Line(draw,s5, s6, col);
    Line(draw,s6, s7, col);
    Line(draw,s7, s8, col);
    Line(draw,s8, s5, col);
 
    Line(draw,s1, s5, col);
    Line(draw,s2, s6, col);
    Line(draw,s3, s7, col);
    Line(draw,s4, s8, col);

}
}

FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
 bool flag = false;
 double num = (double)Yaw;
 double num2 = num * 0.017453292519943295;
 float num3 = (float)std::cos(num2);
 float num4 = (float)std::sin(num2);
 float num5 = Origin.X - LocalOrigin.X;
 float num6 = Origin.Y - LocalOrigin.Y;
 struct FVector Xector;
 Xector.X = (num6 * num3 - num5 * num4) / 150.f;
 Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
 struct FVector Xector2;
 Xector2.X = Xector.X + PosX + Size.X / 2.f;
 Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
 bool flag2 = Xector2.X > PosX + Size.X;
 if (flag2) {
  Xector2.X = PosX + Size.X;
 }else{
  bool flag3 = Xector2.X < PosX;
  if (flag3) {
   Xector2.X = PosX;
  }
 }
 bool flag4 = Xector2.Y > PosY + Size.Y;
 if (flag4) {
  Xector2.Y = PosY + Size.Y;
 }else{
  bool flag5 = Xector2.Y < PosY;
  if (flag5){
   Xector2.Y = PosY;
  }
 }
 bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
 if (flag6){
  flag = true;
 }
 outbuff = flag;
 return Xector2;
}

std::string deviceBrandModel() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    
        std::string Device;
		Device += "ANDROID  >  ℅d  - ";
        Device += Tools::GetDeviceBrand(env);
		Device += " - ";
        Device += Tools::GetDeviceModel(env);
    vm->DetachCurrentThread();

    return Device;
}

int KAUSHIK_FLOAT(long int addr, float value){
    Tools::WriteAddr((void*)(addr), (void*)&value , 4);
    return 0;
}
//------------ ESP DRAW FUNCTION --------------//
void DrawESP(ImDrawList *draw) {
if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {


std::string Device = deviceBrandModel();
draw->AddText(Injector, ((float) density / 12.0f),{(float) glWidth / 150 + glWidth / 40,650},IM_COL32(255, 255, 255, 255),Device.c_str());

        auto Actors = getActors();
        int totalEnemies = 0, totalBots = 0;

        ASTExtraPlayerCharacter *localPlayer = 0;
        ASTExtraPlayerController *localController = 0;
		

        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
                localController = (ASTExtraPlayerController *) Actor;
                break;
            }
        }
          if (localController) {
            for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                    if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey ==
                        localController->PlayerKey) {
                        localPlayer = (ASTExtraPlayerCharacter *) Actor;
                        break;
                    }
                }
            }


                            if (localPlayer) {
                    if (localPlayer->PartHitComponent) {
                        auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                        for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                            ConfigCollisionDistSqAngles[j].Angle = 180.0f;
                        }
                        localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                    }
					
                    static bool bShooting = false;
                 if (Config.SilentAim.Enable) {
                   auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                if (WeaponManagerComponent) {
                    auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                    if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                        if (CurrentWeaponReplicated) {
                            auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                            if (ShootWeaponComponent) {
                                int shoot_event_idx = 168;
                                auto VTable = (void **) ShootWeaponComponent->VTable;
                                auto f_mprotect = [](uintptr_t addr, size_t len,
                                int32_t prot) -> int32_t {
                                    static_assert(PAGE_SIZE == 4096);
                                    constexpr
                                    size_t page_size = static_cast<size_t>(PAGE_SIZE);
                                    void *start = reinterpret_cast<void *>(addr &
                                                                           -page_size);
                                    uintptr_t end =
                                    (addr + len + page_size - 20) & -page_size;
                                    return mprotect(start, end -
                                                    reinterpret_cast<uintptr_t>(start),
                                                    prot);
                                };
                                if (VTable && (VTable[shoot_event_idx] != shoot_event)) {
                                    orig_shoot_event = decltype(orig_shoot_event)(
                                                           VTable[shoot_event_idx]);

                                    f_mprotect((uintptr_t)(&VTable[shoot_event_idx]),
                                               sizeof(uintptr_t), PROT_READ | PROT_WRITE);
                                    VTable[shoot_event_idx] = (void *) shoot_event;
                                }
                            }
                        }
                    }
                }
            }

	
			
			
if(Config.HighRisk.Autofire){
  if (GetTargetByPussy()) {
    localController->bIsPressingFireBtn = true;
  } else {
    qwcifqvs86y8fify = true;
  }
}


if (WideView){
localPlayer->ThirdPersonCameraComponent->SetFieldOfView(WideViewRange);
}

           
				  if (Config.AimBot.Enable)
				{
					ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
					if (Target)
					{
						bool triggerOk = false;
						if (Config.AimBot.Trigger != EAimTrigger::Scoping)
						{
							if (Config.AimBot.Trigger == EAimTrigger::None)
							{
								triggerOk = localPlayer->bIsWeaponFiring;
							}
							else if (Config.AimBot.Trigger == EAimTrigger::Shooting)
							{
								triggerOk = localPlayer->bIsGunADS;
							}
							else if (Config.AimBot.Trigger == EAimTrigger::Both)
							{
								triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
							}
							else if (Config.AimBot.Trigger == EAimTrigger::Any)
							{
								triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
							}
						}
						else
							triggerOk = true;
								if (triggerOk)
						{
						FVector targetAimPos = Target->GetBonePos("Head", {});
							if (Config.AimBot.Target == EAimTarget::Chest)
							{
								targetAimPos.Y -= 1.228f;
								targetAimPos.Z -= 25.0f;
							//	targetAimPos.X -= Config.Skill4;
							}
										
										auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
							if (WeaponManagerComponent)
							{
								auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
								if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3)
								{
									auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
									if (CurrentWeaponReplicated)
									{
										auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
										if (ShootWeaponComponent)
										{
											UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
											if (ShootWeaponEntityComponent)
											{
												ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
												if (CurrentVehicle)
												{
													FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
													float dist = localPlayer->GetDistanceTo(Target);
													auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
													targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
												}
												else
												{
													FVector Velocity = Target->GetVelocity();
													float dist = localPlayer->GetDistanceTo(Target);
													auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
													targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
													
													/*targetAimPos.Z += Velocity.Z * timeToTravel + 0.5 * Config.Line * timeToTravel * timeToTravel;    */
												}
												
												if (Config.AimBot.Enable) {
                            if (g_LocalPlayer->bIsGunADS) {
                               if (g_LocalPlayer->bIsWeaponFiring) {
                                float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                targetAimPos.Z -= dist * 1.25f;        
                                
                                                          
                                }  
                             }
                           }  
												
							g_LocalController->ControlRotation =ToRotator(g_LocalController->PlayerCameraManager->CameraCache.POV.Location,                                                     targetAimPos);//修复自瞄卡屏代码

                                        }
									}
								}
							}
						}
					}
				}      
				}      
			
											
			    	if(ActiveAllesp){
			         Config.Mrkaushikhaxor.LineTop = true;
					 Config.Mrkaushikhaxor.Health = true;
					 Config.Mrkaushikhaxor.Distance = true;
					 Config.Mrkaushikhaxor.Skeleton = true;
					// Config.Mrkaushikhaxor.Box = true;
					 Config.Mrkaushikhaxor.TeamID = true;
					 Config.Mrkaushikhaxor.Name = true;
					 Config.Mrkaushikhaxor.Alert = true;
					 WideView = true;

					 }
					 if(Config.AimBot.Enable){
					 Config.AimBot.Pred = true;
					 Config.AimBot.VisCheck = true;
					 Config.AimBot.IgnoreKnocked = true;
                     }
	
				
           
		
									
              for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                         if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                            auto Player = (ASTExtraPlayerCharacter *) Actor;

                           float Distance = localPlayer->GetDistanceTo(Player) /100.0f;
                            if (Distance > 500.0f)
                                continue;
                            if (Player->PlayerKey == localController->PlayerKey)
                                continue;

                            if (Player->TeamID == localController->TeamID)
                                continue;
								
							if (Player->bDead)
                                continue;

                            if (!Player->Mesh)
                                continue;
                            
                          
							
							bool IsVisible = localController->LineOfSightTo(Player, {0, 0, 0}, true);
							int SCOLO;
                            int SCOLOR;
                            int SCOLOR2;
                            int SCOLOR3;
							int SCOLOR4;
							int HPColor25;
							int HPColor50;
							int HPColor75;
							int HPColor100;
							int HPColorKnock;
							int HPPColorbg;
							int HPPColorKnock;

                        if (IsVisible){
                        SCOLOR = IM_COL32(0, 255, 0, 255);
                        SCOLOR2 = IM_COL32(0, 255, 0, 255);
						SCOLOR3 = IM_COL32(0, 255, 0, 180);
						SCOLOR4 = IM_COL32(0, 255, 0, 180);
						}else{
                        SCOLOR = IM_COL32(255, 0, 0, 255);
                        SCOLOR2 = IM_COL32(0, 255, 0, 255);
						SCOLOR3 = IM_COL32(255, 0, 0, 180);
						SCOLOR4 = IM_COL32(0, 255, 0, 180);
						}
                            
                        if (Player->bEnsure){
					    totalBots++;
                        SCOLOR2 = IM_COL32(255, 255, 255, 180);
                        SCOLOR = IM_COL32(255, 255, 255, 255);//Line
						SCOLOR3 = IM_COL32(255, 255, 255, 180);
					    SCOLOR4  = IM_COL32(255, 255, 255, 180);//Skl
					    
					   HPColor100 = IM_COL32(255, 255, 0, 0);
						HPColorKnock = IM_COL32(255, 0, 0, 0);
						HPPColorKnock = IM_COL32(0, 0, 0, 0);
						HPPColorbg = IM_COL32(0, 0, 0, 0);
						}else{
						totalEnemies++;
						HPColor100 = IM_COL32(0, 255, 0, 255);
						HPColorKnock = IM_COL32(255, 0, 0, 255);
						HPPColorKnock = IM_COL32(0, 0, 0, 255);
						HPPColorbg = IM_COL32(0, 0, 0, 255);
						}
							

						
            if (Config.Mrkaushikhaxor.Alert){
                    bool shit = false;
                            FVector MyPosition, EnemyPosition;
                            ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            if (CurrentVehiclea) { 
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else { 
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
                            FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(glWidth, glHeight, 0), shit);  
                            FVector angle = FVector();
                            Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);  
                            VectorAnglesRadar(forward, angle);
                            const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
                            const auto new_point_x = (glWidth / 2) + (55) / 2 * 8 * cosf(angle_yaw_rad);  
                            const auto new_point_y = (glHeight / 2) + (55) / 2 * 8 * sinf(angle_yaw_rad);  
                            std::array<Vector3, 3> points { Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                          
      
        
        std::string s;
        s += std::to_string((int)Distance);   
        auto textSize = ImGui::CalcTextSize(s.c_str(), 0, ((float) density / 20.0f));
      if (Player->bEnsure) {
       //draw->AddCircleFilled(ImVec2(new_point_x, new_point_y), 5.0f, SCOLOR3);
       } else {
		draw->AddText(Injector, ((float) density / 23.0f), {new_point_x - (textSize.x / 2), new_point_y + 5.f}, IM_COL32(255,255,255,255), s.c_str());                 
        RotateTriangle(points, angle.Y + 180.f); 
        draw->AddCircle(ImVec2(new_point_x, new_point_y), 9.0f, IM_COL32(255,255,255,255)); 
        draw->AddCircleFilled(ImVec2(new_point_x, new_point_y), 5.0f, SCOLOR3);
       
 }}
							
							if (Config.Mrkaushikhaxor.NoBot)
						    if (Player->bEnsure)
                            continue;
                            FVector HeadPos = Player->GetBonePos("Head", {});
                            HeadPos.Z = HeadPos.Z + 1.0f; //head se line ooper
                            ImVec2 HeadPosSC;

                            FVector RootPos = Player->GetBonePos("Root", {});
                            ImVec2 RootPosSC;
							
							                              FVector Root = Player->GetBonePos("Root", {});
                             FVector Spin = Player->GetBonePos("Pelvis", {});
                             FVector Spin2 = Player->GetBonePos("spine_03", {});
                              auto Pelvis = Player->GetBonePos("Pelvis", {});
                             ImVec2 PelvisPoSC;
               
            auto upper_r = Player->GetBonePos("upperarm_r", {});
            ImVec2 upper_rPoSC;
            auto lowerarm_r = Player->GetBonePos("lowerarm_r", {});
            ImVec2 lowerarm_rPoSC;
            auto hand_r = Player->GetBonePos("hand_r", {});
            ImVec2 hand_rPoSC;
            auto upper_l = Player->GetBonePos("upperarm_l", {});
            ImVec2 upper_lPoSC;
            auto lowerarm_l = Player->GetBonePos("lowerarm_l", {});
            ImVec2 lowerarm_lSC;
            auto hand_l = Player->GetBonePos("hand_l", {});
            ImVec2 hand_lPoSC;
            auto thigh_l = Player->GetBonePos("thigh_l", {});
            ImVec2 thigh_lPoSC;
            auto calf_l = Player->GetBonePos("calf_l", {});
            ImVec2 calf_lPoSC;
            auto foot_l = Player->GetBonePos("foot_l", {});
            ImVec2 foot_lPoSC;
             auto thigh_r = Player->GetBonePos("thigh_r", {});
             ImVec2 thigh_rPoSC;
             auto calf_r = Player->GetBonePos("calf_r", {});
             ImVec2 calf_rPoSC;
                  
             auto foot_r = Player->GetBonePos("foot_r", {});
             ImVec2 foot_rPoSC;
             auto neck_01 = Player->GetBonePos("neck_01", {});
             ImVec2 neck_01PoSC;
             auto spine_01 = Player->GetBonePos("spine_01", {});
             ImVec2 spine_01PoSC;
             auto spine_02 = Player->GetBonePos("spine_02", {});
             ImVec2 spine_02PoSC;
             auto spine_03 = Player->GetBonePos("spine_03", {});
             ImVec2 spine_03PoSC;
             if (W2S(HeadPos, (FVector2D *) & HeadPosSC) && W2S(upper_r, (FVector2D *) & upper_rPoSC) && W2S(upper_l, (FVector2D *) & upper_lPoSC) && W2S(lowerarm_r, (FVector2D *) & lowerarm_rPoSC) && W2S(hand_r, (FVector2D *) & hand_rPoSC) && W2S(lowerarm_l, (FVector2D *) & lowerarm_lSC) && W2S(hand_l, (FVector2D *) & hand_lPoSC) && W2S(thigh_l, (FVector2D *) & thigh_lPoSC) && W2S(calf_l, (FVector2D *) & calf_lPoSC) && W2S(foot_l, (FVector2D *) & foot_lPoSC) && W2S(thigh_r, (FVector2D *) & thigh_rPoSC) && W2S(calf_r, (FVector2D *) & calf_rPoSC) && W2S(foot_r, (FVector2D *) & foot_rPoSC) && W2S(neck_01, (FVector2D *) & neck_01PoSC) && W2S(Pelvis, (FVector2D *) & PelvisPoSC) && W2S(RootPos, (FVector2D *) & RootPosSC) && W2S(spine_01, (FVector2D *) & spine_01PoSC)&& W2S(spine_02, (FVector2D *) & spine_02PoSC)&& W2S(spine_03, (FVector2D *) & spine_03PoSC)) {
		
			
								
                	if (Config.Mrkaushikhaxor.LineTop) {
						draw->AddLine({(float) glWidth / 2, 60}, HeadPosSC,
                                                  SCOLOR, 1.0f);
												  
												  }
		
if (Config.Mrkaushikhaxor.Box) {
float boxHeight = abs(HeadPosSC.y - RootPosSC.y);
float boxWidth = boxHeight * 0.65f;
Box4Line(draw, 0.5f, HeadPosSC.x - (boxWidth / 2), HeadPosSC.y, boxWidth, boxHeight, SCOLOR);
		}			

							
								
								

		
							
if (Config.Mrkaushikhaxor.Skeleton) {							
if (Distance < 30) {
draw->AddCircleFilled({neck_01PoSC.x, neck_01PoSC.y}, 2, IM_COL32(255, 255, 255, 255));//脖子
draw->AddCircleFilled({upper_rPoSC.x, upper_rPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//右上臂
draw->AddCircleFilled({upper_lPoSC.x, upper_lPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//左上臂
draw->AddCircleFilled({lowerarm_rPoSC.x, lowerarm_rPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//右下臂
draw->AddCircleFilled({lowerarm_lSC.x, lowerarm_lSC.y}, 2, IM_COL32(255, 255, 255, 255));//左下臂
draw->AddCircleFilled({thigh_rPoSC.x, thigh_rPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//右大腿
draw->AddCircleFilled({thigh_lPoSC.x, thigh_lPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//左大腿
draw->AddCircleFilled({calf_lPoSC.x, calf_lPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//左小腿
draw->AddCircleFilled({calf_rPoSC.x, calf_rPoSC.y}, 2, IM_COL32(255, 255, 255, 255));//右小腿
}				
											
											
		            long Chead,Cuparmr,Cuparml,Clowarmr,Clowarml,Cthighl,Cthighr,Ccalfl,Ccalfr,Cneck,CPelvis,Cspine1,Cspine2,Cspine3;  
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("neck_01", {}), true))
                    {
                    Cneck = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cneck = IM_COL32(0, 255, 0, 255); 
                    }
                    
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("upperarm_r", {}), true))
                    {
                    Cuparmr = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cuparmr = IM_COL32(0, 255, 0, 255); 
                    }
                    
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("upperarm_l", {}), true))
                    {
                    Cuparml = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cuparml = IM_COL32(0, 255, 0, 255); 
                    }
                    
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("lowerarm_r", {}), true))
                    {
                    Clowarmr = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Clowarmr = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("lowerarm_l", {}), true))
                    {
                    Clowarml = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Clowarml = IM_COL32(0, 255, 0, 255); 
                    }
                    
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("spine_03", {}), true))
                    {
                    Cspine3 = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cspine3 = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("spine_02", {}), true))
                    {
                    Cspine2 = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cspine2 = IM_COL32(0, 255, 0, 255);
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("spine_01", {}), true))
                    {
                    Cspine1 = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cspine1 = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("Pelvis", {}), true))
                    {
                    CPelvis = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    CPelvis = IM_COL32(0, 255, 0, 255); 
                    }                
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("thigh_l", {}), true))
                    {
                    Cthighl = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cthighl = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("thigh_r", {}), true))
                    {
                    Cthighr = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Cthighr = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("calf_l", {}), true))
                    {
                    Ccalfl = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Ccalfl = IM_COL32(0, 255, 0, 255); 
                    }
                    if(!localController->LineOfSightTo(localController->PlayerCameraManager,Player->GetBonePos("calf_r", {}), true))
                    {
                    Ccalfr = IM_COL32(255, 0, 0, 255); 
                    }
                    else
                    {
                    Ccalfr = IM_COL32(0, 255, 0, 255); 
                    }
                    
                    
                      draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, neck_01PoSC, Cneck, 1.0f);
                      draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, neck_01PoSC, Cneck, 1.0f);
                      draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, lowerarm_rPoSC, Cuparmr, 1.0f);
                      draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y}, hand_rPoSC, Clowarmr, 1.0f);
                      draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, lowerarm_lSC, Cuparml, 1.0f);
                      draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y}, hand_lPoSC, Clowarml, 1.0f);
                      draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, thigh_lPoSC, Cthighl, 1.0f);
                      draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y}, calf_lPoSC, Cthighl, 1.0f);
                      draw->AddLine({calf_lPoSC.x, calf_lPoSC.y}, foot_lPoSC, Ccalfl, 1.0f);
                      draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, calf_rPoSC, Cthighr, 1.0f);
                      draw->AddLine({calf_rPoSC.x, calf_rPoSC.y}, foot_rPoSC, Ccalfr, 1.0f);
                      draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, spine_03PoSC, Cspine3, 1.0f);
                      draw->AddLine({spine_03PoSC.x, spine_03PoSC.y}, spine_02PoSC, Cspine2, 1.0f);
                      draw->AddLine({spine_02PoSC.x, spine_02PoSC.y}, spine_01PoSC, Cspine1, 1.0f);
                      draw->AddLine({spine_01PoSC.x, spine_01PoSC.y}, PelvisPoSC, CPelvis, 1.0f);
                      draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, HeadPosSC, Cneck, 1.0f);
                                }	
											
			
											
							if (Config.Mrkaushikhaxor.Health) {
                              
                                                int CurHP = (int) std::max(0, std::min(
                                                        (int) Player->Health,
                                                        (int) Player->HealthMax));
                                                int MaxHP = (int) Player->HealthMax;

                                            
										              long HPColor = HPColor100;
													

                                                
                                                if (Player->Health == 0.0f && !Player->bDead) {
                                                    HPColor = HPColorKnock;
													//HPPColorbg = HPPColorKnock;

                                                    CurHP = Player->NearDeathBreath;
                                                    if (Player->NearDeatchComponent) {
                                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                                    }
                                                }
                
                                    float boxWidth = density / 7.0f;
                                    boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance, boxWidth / 2);
                                    float boxHeight = boxWidth * 0.13f;
									
                                    ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2), HeadPosSC.y - (boxHeight * 2.0f)};

                                    ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP), vStart.y + boxHeight};
                                    ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};
									
                                    draw->AddRectFilled(vStart, vEndRect, HPPColorbg);
                                    draw->AddRectFilled(vStart, vEndFilled, HPColor);
			
									}
									
									
									
									
									
									
							if (Config.Mrkaushikhaxor.Name){
									float boxWidth = density / 1.6f;
                                                boxWidth -= std::min(
                                                        ((boxWidth / 2) / 00.0f) * Distance,
                                                        boxWidth / 2);
                                                float boxHeight = boxWidth * 0.13f;


                                                std::string s;
                                                if (Player->bEnsure) {
                                                s += "";
                                                } else {
                                                s += Player->PlayerName.ToString();
                                                }
                                                draw->AddText(Injector2,((float) density / 27.0f),//24.0f
                                                              {HeadPosSC.x - (boxWidth / 4.5),//3.5f
                                                      HeadPosSC.y - (boxHeight * 1.499)},//1.83f
                                                              IM_COL32(255, 255, 255, 255),
                                                              s.c_str());
                                                
							
				}
				
			
			
			
			
if (Config.Mrkaushikhaxor.Distance){
std::string s;
float boxWidth = density / 1.6f;//1.6f
boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance,boxWidth / 2);
float boxHeight = boxWidth * 0.13f;//0.13f
 if (Player->bEnsure) {
s += "";
} else {
s += "[ ";
s += std::to_string(Player->TeamID);
s += " ] ";
s += std::to_string((int) Distance);
s += " M";
auto textSize = ImGui::CalcTextSize(s.c_str(), 0, ((float) density / 35.0f));
draw->AddText(Injector2, ((float) density / 25.0f),//35.0f
		{RootPosSC.x - (textSize.x / 4.5), RootPosSC.y},//3.5
		IM_COL32(255,255,255, 255), s.c_str());
}}}}
		
                     				 
    if (Actors[i]->IsA(ASTExtraGameStateBase::StaticClass()))
    {
        auto InGame = (ASTExtraGameStateBase *)Actors[i];
        std::string s;
        if ((int)InGame->AliveTeamNum == 1){
            std::vector<std::string> lines = {"#1 Madr By ~ Kaushik "};

            float textPosY = 450; //420
            for (const auto &line : lines)
            {
                auto textSize = ImGui::CalcTextSize(line.c_str(), 0, line.size());
                float textPosX = (glWidth - textSize.x) / 2.3;//2
                draw->AddText(Injector, ((float)density / 8.5),//10.0f
                 ImVec2(textPosX, textPosY), IM_COL32(255, 255, 0, 255), line.c_str());
                textPosY += textSize.y + 25; //25
            }}}			
				
					
						
				
                            if (Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
                                auto Grenade = (ASTExtraGrenadeBase *) Actor;
                                 
                                std::string n = getObjectPath(Grenade);
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
								 if (Distance > 100)
                                   continue;
								
                                FVector2D grenadePos;

                                if (W2S(Grenade->K2_GetActorLocation(), &grenadePos)) {
                                    std::string s;
                                    if(n=="BP_Grenade_Smoke_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        s+="Smoke";
                                    } else if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        s+="Molotov";
                                    } else if(n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        s+="Grenade";
                                    } else if(n=="BP_Grenade_PoisonApple_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        s+="Apple";
                                    } else {
                                    s += " ";
                                    }
                                    s += " - ";
                                    s += std::to_string((int) Distance);
                                    s += "M";
                                   
                                    auto textSize = ImGui::CalcTextSize2(s.c_str(), 0,
                                                                         ((float) density / 22.0f));
                                    draw->AddText(Injector2, ((float) density / 22.0f),
                                                  {(grenadePos.X - (textSize.x / 2)), grenadePos.Y},
                                                  ImColor(isRedV2, isBlueV2, isGreenV2, 8.0f),s.c_str());
                                }
                            }
                        
						
						
						
						
						
         				   if (Actors[i]->IsA(APickUpWrapperActor::StaticClass())) {
                            auto PickUp = (APickUpWrapperActor *) Actors[i];
						if (Items[PickUp->DefineID.TypeSpecificID]){
							auto RootComponent = PickUp->RootComponent;
							if (!RootComponent)
								continue;
		            float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                    if (Distance > 20)
                        continue;
						if (PickUp->bHidden)
						continue;
						
					        FVector2D itemPos;
                            if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
                                std::string s;
                                uint32_t tc = 0xFF000000;

                                for (auto &category: items_data) {
                                    for (auto &item: category["Items"]) {
                                        if (item["itemId"] == PickUp->DefineID.TypeSpecificID) {
                                            s = item["itemName"].get<std::string>();
                                            tc = strtoul(
                                                    item["itemTextColor"].get<std::string>().c_str(),
                                                    0, 16);
                                            break;
                                    }
                                }
                            }

                            s += " - ";
                            s += std::to_string((int) Distance);
                            s += "M";
							
							draw->AddText(Injector2, ((float) density / 28.0f),{itemPos.X, itemPos.Y}, tc, s.c_str());
						}
                    }
                }
            }
        }
	 }
	    if (bValid) {
    	g_LocalController = localController;
		g_LocalPlayer = localPlayer;
        std::string credit1  = OBFUSCATE("                                ©-Telegram Dm -> @Mrkaushikhaxor");
	    std::string credit2 =  OBFUSCATE("                                ©-Telegram Dm -> @Mrkaushikhaxor");
        std::string credit3 =  OBFUSCATE("                                ©-Telegram Dm -> @Mrkaushikhaxor");
        
	   auto textSize = ImGui::CalcTextSize2(credit1.c_str(), 0, ((float) density / 10.5f));
       draw->AddText(Injector, ((float) density / 10.5f), {((float) glWidth / 2) - (textSize.x / 2), 25}, IM_COL32(255, 255, 255, 255), credit1.c_str());
	   draw->AddText(Injector, ((float) density / 10.5f), {((float) glWidth / 2) - (textSize.x / 2), 25}, IM_COL32(255, 255, 255, 255), credit2.c_str());
       draw->AddText(Injector, ((float) density / 10.5f), {((float) glWidth / 2) - (textSize.x / 2), 25}, IM_COL32(255, 0, 0, 255), credit3.c_str());
	   
	  
if(Config.AimBot.Enable){
draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, IM_COL32(255, 255, 255, 255), 100, 1.0f);
}}
fps.update();
}}
// ======================================================================== //
#include "Includes/Login.h"

                     if(InjectUi){
                     if (Config.Mrkaushikhaxor.EUI == EEspUI::UI1) {
                     if (ImGui::Begin("##AUTO", 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar )) {			 
			         Config.Mrkaushikhaxor.LineTop = true;
					 Config.Mrkaushikhaxor.Health = true;
					 Config.Mrkaushikhaxor.Distance = true;
					 Config.Mrkaushikhaxor.Skeleton = true;
					 Config.Mrkaushikhaxor.TeamID = true;
					 Config.Mrkaushikhaxor.Name = true;
					 Config.Mrkaushikhaxor.Alert = true;
					 WideView = true;
					 Config.AimBot.Enable = true;
					 Config.AimBot.Pred = true;
					 Config.AimBot.VisCheck = true;
					 Config.AimBot.IgnoreKnocked = true;
                     }
                     ImGui::End();
					 }

			         if (Config.Mrkaushikhaxor.EUI == EEspUI::UI2) {
                     if (ImGui::Begin("##AUTO", 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar )) {			 
			         Config.Mrkaushikhaxor.LineTop = true;
					 Config.Mrkaushikhaxor.Health = true;
					 Config.Mrkaushikhaxor.Distance = true;
					 Config.Mrkaushikhaxor.Skeleton = true;
					 Config.Mrkaushikhaxor.TeamID = true;
					 Config.Mrkaushikhaxor.Name = true;
					 Config.Mrkaushikhaxor.Alert = true;
					 WideView = true;
					 Config.SilentAim.Enable = true;
					 Config.AimBot.VisCheck = false;
					 Config.AimBot.IgnoreKnocked = false;
                     }
                     ImGui::End();
					 }
					 }
					 
static std::string MOD_NAME = OBFUSCATE("KAUSHIK 2.1 | ( Private V1) ARM64-v8a");


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||
                    
                     if (ImGui::Begin("##AUTO", 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar )) {
                     if (bValid){
	                 }else{
                     LoginAnnouncementBykaushik(LOGINT.c_str());
                     } 
					 
					 static bool sKAUSHIK1 = "f";
                     static bool sKAUSHIK2 = "a";
                     static bool sKAUSHIK3 = "l";
                     static bool sKAUSHIK4 = "s";
                     static bool sKAUSHIK5 = "e";
                     static bool isLogin, logginIn = sKAUSHIK1+sKAUSHIK2+sKAUSHIK3+sKAUSHIK4+sKAUSHIK5;
					 
					 static std::string err;             				 
                     if (!isLogin) {
	                 ImGui::Text(OBFUSCATE(""));
			         ImGui::PushItemWidth(-1);
                     static char s[64];
                     auto key = getClipboardText();
                     strncpy(s, key.c_str(), sizeof s);
                     err = Login(s);
                     if (err == "OK") {
                     isLogin = bValid && g_Auth == g_Token;}
                     err = Login(s);
                     if (err == "OK") {
                     isLogin = bValid && g_Auth == g_Token;}
					 if (!err.empty() && err != "OK") {
					 OpenURL(OBFUSCATE("https://telegram.me/Mrkaushikhaxor"));
                     //LoginAnnouncementBykaushik(LOGINT.c_str());
                     ImGui::Text("", err.c_str());                
			         }}else{
					 if (bValid){
					 if(InjectHack){
					 ImGui::SetNextWindowSize(ImVec2(270,220));//270 + 220
	                 ImGui::Begin("##Injector",&InjectHack,ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize );{
					 ImGui::PushFont(Injector3);
					 ImGui::Text("UI :");
					 ImGui::SameLine();
					 static const char *tesp[] = {" NONE UI" , " ESP + AIM"," ESP + BT"," GG - MENU"};
                	 ImGui::Combo("", (int *) &Config.Mrkaushikhaxor.EUI, tesp, 4, -0);
					 ImGui::Spacing();
					 ImGui::Text("• Select UI Your Choice !");
					 ImGui::Text("• Select After Inject UI !");
					 if(ImGui::OptButton1(OBFUSCATE("Inject UI"),ImVec2(240, 45))) {
					 InjectHack = false;
					 InjectUi = true;				 
					 }
					 ImGui::PopFont();
					 }}
					 }//bvalid
					 
					 if(InjectUi){
                     if (Config.Mrkaushikhaxor.EUI == EEspUI::UI3) {
					 ImGui::SetNextWindowSize(ImVec2(630,470));//630+450
					 if (ImGui::Begin(MOD_NAME.c_str(),&NEWMENU,ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize)){
				     #include "Includes/BgLineAnimation.h"		 
					 ImGui::SetCursorPos( ImVec2(15, 90) );//15 / 100
                	 ImGui::MenuChild(OBFUSCATE("--- GG BRUTAL MENU --- "), ImVec2(600, 310) );{//550 , 220
				     #include "Includes/BgLineAnimation.h"
					 if (ImGui::BeginTable("split", 3));{
					 ImGui::TableNextColumn();
					 ImGui::Spacing();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("AimBot", &Config.AimBot.Enable);
					 ImGui::TableNextColumn();
					 ImGui::Spacing();
					 //ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Silent Aim", &Config.SilentAim.Enable);
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Bullet Track", &Config.BulletTrack.Enable);
					 ImGui::TableNextColumn();
					 ImGui::Spacing();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("M - Bullet", &Magic);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("RGB X Effect", &ggxhitXhitRainBow);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("RGB Cross", &Config.HighRisk.SmallCrossRgbCross);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Fast Para", &FASTPARACHUTE);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Sdk Flash", &SdkFlash);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Slow Motion", &SlowMotion);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Zoom +", &Zoom);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Snow + Rain", &Config.HighRisk.RainSnow);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Player Dance", &PlayerDance);
					 ImGui::TableNextColumn();
					 ImGui::𝙆𝘼𝙐𝙎𝙃𝙄𝙆("Auto Fire", &Config.HighRisk.Autofire);
					 ImGui::TableNextColumn(); 
					 ImGui::EndTable();}
				     ImGui::SliderFloat("Set Wind View", &WideViewRange, 80.0f, 160.0f);
					 ImGui::Spacing();
					 ImGui::PushFont(Social);
					 ImGui::SetCursorPos(ImVec2( 310 - 15 - 50 - 30 - 20,  260));
					 if(ImGui::OptButton2("V", ImVec2(50, 35), false)){
					 OpenURL(OBFUSCATE("https://t.me/Mrkaushikhaxor"));}         
				     ImGui::SetCursorPos(ImVec2( 310 - 15 - 20,  260));               
                     if(ImGui::OptButton2("W", ImVec2(50, 35), false)){
					 OpenURL(OBFUSCATE("https://youtube.com/shorts/ByVonzqiF20?si=9FqHTZUvmS0OOBef"));}         
				     ImGui::SetCursorPos(ImVec2( 310 + 15 + 50 - 20, 260));               
                     if(ImGui::OptButton2("F", ImVec2(50, 35), false)){
					 OpenURL(OBFUSCATE("https://discord.com/invite/ygS5ry2k"));} 
				     ImGui::PopFont();
					 ImGui::EndChild();}
					 ImGui::Spacing();
					 if(ImGui::OptButton1(OBFUSCATE("[ Tap To Inject Hack ]"),ImVec2(600, 45))) {
					 ActiveAllesp = true;
					 }
					 for (auto &i: items_data) {
                     int itemCount = 0;
                     for (auto &item: i[("Items")]) {
                     item[("itemName")].get<std::string>().c_str();
                     Items[item[("itemId")].get<int>()] = true;-
                     itemCount++;
                     if (itemCount % 4 != 0 && &item != &i[("Items")].back()) {
				     }}}
					 }}

						 
				 
}}}
//}

ImGui::End();
ImGui::Render();

ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
return orig_eglSwapBuffers(dpy, surface);
}
int32_t (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);
int32_t onInputEvent(struct android_app *app, AInputEvent *inputEvent) {
if (initImGui) {
ImGui_ImplAndroid_HandleInputEvent(inputEvent, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});
}
return orig_onInputEvent(app, inputEvent);
}

#include "Includes/Skin.h"

#include "Includes/Logger.h"
#include "Includes/Macros.h"
#include "Includes/Utils.h"
#define LibUE4 ("libUE4.so")
#define Libanogs ("libanogs.so")
#define Libanort ("libanort.so")
#define SLEEP_TIME (1000LL / 60LL)
auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));

#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t 
#include <stdio.h>
#include <dlfcn.h>
#define ARM64_SYSREG uint64_t
DWORD libanogsBase = 0;
DWORD libhdmpveBase = 0;
DWORD libUE4Base = 0;
DWORD libanortBase = 0;
DWORD libAntsVoiceBase = 0;
char *Offset;
typedef __int64 int64;
DWORD NewBase = 0;

typedef unsigned char BYTE;   
typedef BYTE* PBYTE;
#define PackageName "com.pubg.imobile"

void sub_1E8DE0(){
}
void sub_1E8E00(){
}



void *anogs_thread(void *) {
PATCH_LIB("libanogs.so","0x166c24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x193d14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x250754","FC 0F 1E F8");
PATCH_LIB("libanogs.so","0x144650","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x193d14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x131064","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x14CC9C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xDF2F0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x645E0","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x3B4A20","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x3B4A40","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x19E10","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x3FF1F0","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x19DB8","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x3FF248","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x19DB4","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x3FF24C","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x19DB0","h 40 00 00 00");
PATCH_LIB("libanogs.so","0x133DA4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD0E8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD81C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD038","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD370","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD614","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD734","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3E77F8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3E7720","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3E753C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3F8BF4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3D970C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426038","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426040","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426094","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4260F0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4260F8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426154","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4261B0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x42620C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426268","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4262C4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426320","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426384","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x42639C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4263C0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4263CC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4263E4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426408","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426414","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426504","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x42652C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426554","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426674","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x426DCC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569808","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569928","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569929","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992A","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992B","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992D","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992E","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56992F","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569930","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569931","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569932","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569933","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569934","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569935","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569936","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569937","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569938","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569939","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993A","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993B","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993D","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993E","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x56993F","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569940","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569950","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x569958","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF0978","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xF7710","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x158860","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1E90EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x14CC9C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x131064","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x243D50","00 00 80 D2 C0 03 5F D6"); // Online Fix
PATCH_LIB("libanogs.so","0xE3C3C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x166C24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3E8F50","00 00 80 D2 C0 03 5F D6");//Flag
PATCH_LIB("libanogs.so","0x3E8F80","00 00 80 D2 C0 03 5F D6");//Flag
PATCH_LIB("libanogs.so","0x3E8F68","00 00 80 D2 C0 03 5F D6");//Flag
PATCH_LIB("libanogs.so","0xEDD1C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDDA0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDDA8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDD00","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDD98","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDD9C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xEDDA4","00 00 80 D2 C0 03 5F D6");
HOOK_LIB_NO_ORIG("libanogs.so", "0x1E8DE0", sub_1E8DE0);
HOOK_LIB_NO_ORIG("libanogs.so","0x1E8E00",sub_1E8E00);
PATCH_LIB("libanogs.so","0x133014","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1622B0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x168A58","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1B0238","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD12C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DD1A4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x166814","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x17DC38","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1622B0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x243D50","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x243D50","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1E90EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x131064","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x14CC9C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x158860","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x62FF8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xE3C3C","00 00 80 D2 C0 03 5F D6");//10yearfix
PATCH_LIB("libanogs.so","0x3C230C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x166814","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1425B4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xDF2F0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x246380","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAC1F850","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAC1F040","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAC1F030","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAC1EFE0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAC1F0C0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x0B5900E8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x0B464728","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B4AB1A8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x0B4B88B0","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B4CF668","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B05FFA8","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B060358","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B060FB8","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B2AE808","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B2B9880","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x0B2D2588","00 00 80 D2 C0 03 5F D6");	
PATCH_LIB("libUE4.so","0x54E876C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E8774","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9070","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E934C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9488","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9490","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9540","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9930","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9938","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9B88","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54E9B90","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EF2C4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EF2CC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EFDE8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EFDF0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EFE6C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54EFE6C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F16D4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F2C2C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F2D20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F3540","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F43C8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F43D0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54F46D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5181d18","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5181d20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5185d6c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5185f6c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5186900","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5186908","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5186d88","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5186d90","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5186ef4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f4f1c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f50c0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5204","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f520c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5248","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5250","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5288","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5290","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f52c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f52d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5308","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5310","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5348","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5350","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5388","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5390","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f53c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f53d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5508","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5510","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5550","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5588","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5590","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f55c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f55d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5608","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5610","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5648","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5650","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5688","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5690","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f56c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f56d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5708","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5710","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5748","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5750","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5788","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5790","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f57c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f57d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5808","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5810","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5848","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5850","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5888","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5890","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f58c8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f58d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5908","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5910","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5948","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5950","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5988","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5990","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f59d0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f59e4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5a1c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5a24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5a5c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5a64","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5aa8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5ab0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5af4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5afc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5b34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5b3c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5b74","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5b7c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5bb4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5bbc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5bf4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5bfc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5c34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5c3c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5c74","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5c7c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5cb4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5cbc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5cf4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5cfc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5d34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5d3c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5d74","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5d7c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5db4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5dbc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5df4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5dfc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5e34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5e3c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5e74","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5e7c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5eb4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5ebc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5ef4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f5efc","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f64f0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f6978","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f6994","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f6a38","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f6f14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f6f1c","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f7bac","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f7bb4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f7df0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f7df8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f8f10","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x54f8f18","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E4E494","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E59C48","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E59C50","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E59D9C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E59DA4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E60EE8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E60EF0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61134","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61148","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E611D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E611EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61424","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61438","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61528","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E6153C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E6175C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61770","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E6183C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61850","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E618D4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E618E8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61928","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61930","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5E61A00","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x6868300","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x71DCC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x71A30","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x70C5C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6B71C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6AD3C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6A910","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6A6E0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x677DC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x64F58","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x64B88","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x62280","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x62198","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x620D4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5ED24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DED8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DDC0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5882C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57980","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57884","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x577A8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x573F4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x55F4C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8EAE8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8E144","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8DEDC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8D9D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8D564","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8CA48","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8C394","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8BD8C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8AD20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8A654","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8A4F8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x89C94","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x89A84","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x894AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x892EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88318","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88238","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88138","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88040","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x87F34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x87DE4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x87950","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x873FC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x86EF8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x865E4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85ED8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85D8C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85C2C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85B6C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85A14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85694","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85544","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8526C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8526C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x446720","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x44A98","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x44A990","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x44DB30","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x446718","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x446708","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x446710","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x446700","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x4466C8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x4466B8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x55F4C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x573F4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57324","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x577A8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57884","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57980","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5882C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DDC0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DED8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5ED24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x62198","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x62280","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x64B88","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x64F58","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x677DC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6A6E0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6A910","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6AD3C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x6B71C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x71A30","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x71DCC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8526C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85544","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85694","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85A14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x85C2C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x865E4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x86EF8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x87F34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88238","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x88318","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x892EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x894AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8A654","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8BD8C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8EAE8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8E144","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x52898","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57884","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x577A8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5ED24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x573F4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DED8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5DDC0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x5882C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57980","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57324","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x57884","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x55F4C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x52C1C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8D9D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libAntsVoice.so","0x8DEDC","00 00 80 D2 C0 03 5F D6");
return NULL;
}

__attribute__((constructor))
void lib_main() {

    pthread_t ptid;
  pthread_create(&ptid, NULL, anogs_thread, NULL);
  }
//---------------------------------------------------------------------------------------------------------------------------------//
#define SLEEP_TIME 1000LL / 60LL
[[noreturn]]
void * kaushik_thread(void *) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer && localController) {
if(Config.HighRisk.SmallCrossRgbCross){
static float cnt = 0.0f;
const float RainbowSpeed = 18.0f;
const int RainbowColorCount = 7;
const float FullCircle = 360.0f;
const float IncrementValue = 0.02f;
FLinearColor rainbowColors[RainbowColorCount] = {
FLinearColor(1.0f, 0.0f, 0.0f, 1.0f),
FLinearColor(1.0f, 0.5f, 0.0f, 1.0f),
FLinearColor(1.0f, 1.0f, 0.0f, 1.0f),
FLinearColor(0.0f, 1.0f, 0.0f, 1.0f),
FLinearColor(0.0f, 0.0f, 1.0f, 1.0f),
FLinearColor(0.5f, 0.0f, 1.0f, 1.0f),
FLinearColor(1.0f, 0.0f, 1.0f, 1.0f)
};
int rainbowColorIndex = static_cast<int>(fmod(cnt * RainbowSpeed, RainbowColorCount));
FLinearColor color1 = rainbowColors[rainbowColorIndex];
FLinearColor color2 = rainbowColors[(rainbowColorIndex + 1) % RainbowColorCount];
float rainbowPhase = fmod(cnt * RainbowSpeed, 1.0f);
 FLinearColor interpolatedColor = FLinearColor(
color1.R + (color2.R - color1.R) * rainbowPhase,
color1.G + (color2.G - color1.G) * rainbowPhase,
color1.B + (color2.B - color1.B) * rainbowPhase,
1.0f);
localController->CrossHairColor = interpolatedColor;
if (cnt >= FullCircle) {
cnt = 0.0f;
} else {
cnt += IncrementValue;
}}
if (PlayerDance) {
static float DanceValue = 0.0f;
static float DancerValue = 0.0f;
USceneComponent* MeshContainer = localPlayer->MeshContainer;
MeshContainer->RelativeRotation = { 0,DanceValue ,0 };
DanceValue += DancerValue;
if (DanceValue >= 360.0f)
DanceValue = 0.0f;
DanceValue += 30;
}
if (Zoom || Config.HighRisk.SmallCrossRgbCross || Config.HighRisk.SmallAim | Config.HighRisk.RainSnow || Config.BulletTrack.Enable || Config.SilentAim.Enable){
auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
if (WeaponManagerComponent) {
auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
if ((int)Slot.GetValue() >= 1 && (int)Slot.GetValue() <= 3) {
auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
if (CurrentWeaponReplicated) {
auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
if (ShootWeaponEntityComp && ShootWeaponEffectComp) {
if (Zoom){
UCameraComponent *ScopeCameraComp = localPlayer->ScopeCameraComp;
if (ScopeCameraComp){
ScopeCameraComp->SetFieldOfView(SetZoom);
}}
if (Config.HighRisk.SmallCrossRgbCross) {
ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
}
if (Config.HighRisk.SmallAim) {
ShootWeaponEntityComp->IsSupportAutoAim = true;
}
if (Config.HighRisk.RainSnow) {
g_LocalPlayer->STPlayerController->SetIsSnowy(true);
g_LocalPlayer->STPlayerController->SetIsBlizzard(true);
//g_LocalPlayer->STPlayerController->SetIsRainy(true);
}else{
g_LocalPlayer->STPlayerController->SetIsSnowy(false);
g_LocalPlayer->STPlayerController->SetIsBlizzard(false);
//g_LocalPlayer->STPlayerController->SetIsRainy(false);
}

if (Config.BulletTrack.Enable) {
ShootWeaponEntityComp->ShootInterval = 0.03f;
ShootWeaponEntityComp->ExtraShootInterval = 0.03f;}
if (Config.SilentAim.Enable) {
ShootWeaponEntityComp->ShootInterval = 0.03f;
ShootWeaponEntityComp->ExtraShootInterval = 0.03f;}


}}}}}}auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
}
return 0;
}

[[noreturn]]
void * kaushik2_thread(void *) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer && localController) {

if (IpadView) {
auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if (Object->IsA(ULocalPlayer::StaticClass())) {
auto playerChar = (ULocalPlayer *) Object;      
playerChar->AspectRatioAxisConstraint = EAspectRatioAxisConstraint::AspectRatio_MaintainYFOV;
}}}

	
if (ggxhitXhitRainBow){
kFox::SetSearchRange(RegionType::ALL);
kFox::MemorySearch("10.0", Type::TYPE_FLOAT);
kFox::MemoryOffset("46.0", 4, Type::TYPE_FLOAT);
kFox::MemoryWrite("2999.0", 0, Type::TYPE_FLOAT);
kFox::ClearResult();}

if(Magic){
kFox::SetSearchRange(RegionType::ALL);
kFox::MemorySearch("25", Type::TYPE_FLOAT);
kFox::MemoryOffset("30.5", 4, Type::TYPE_FLOAT);
kFox::MemoryWrite("700.5", 0, Type::TYPE_FLOAT);
kFox::MemoryWrite("700.5", 4, Type::TYPE_FLOAT);
kFox::ClearResult();
kFox::SetSearchRange(RegionType::ALL);
kFox::MemorySearch("-88.66608428955", Type::TYPE_FLOAT);
kFox::MemoryOffset("26", 8, Type::TYPE_FLOAT);
kFox::MemoryWrite("-460", 8, Type::TYPE_FLOAT);
kFox::ClearResult();
kFox::SetSearchRange(RegionType::ALL);
kFox::MemorySearch("-88.73961639404", Type::TYPE_FLOAT);
kFox::MemoryOffset("28", 8, Type::TYPE_FLOAT);
kFox::MemoryWrite("-560", 8, Type::TYPE_FLOAT);
kFox::ClearResult();}

if (SdkFlash) {
auto GWorld = GetWorld();GWorld->PersistentLevel->WorldSettings->MinUndilatedFrameTime = 0.100f;}
if (SlowMotion) {
localPlayer->STPlayerController->AcknowledgedPawn->CustomTimeDilation = 0.08f;}

if (FASTPARACHUTE) {
auto objs = UObject::GetGlobalObjects();
for (int i = 0;i < objs.Num();i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
UCharacterParachuteComponent *ParachuteComponent = g_LocalPlayer->ParachuteComponent;
if (ParachuteComponent){
localPlayer->ParachuteComponent->CurrentFallSpeed = 4999.9f;
}}}

}auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
}
return 0;
}

[[noreturn]]
void * kaushik3_thread(void *) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer && localController) {
if (ggxhitXhitRainBow) {
 auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if (Object->IsA(ASurviveHUD::StaticClass())) {
auto xRGB = (ASurviveHUD*)Object;
static float cnt = 0.0f;
const float rainbowSpeed = 18.0f;
FLinearColor rainbowColors[] = {
FLinearColor(1.0f, 0.0f, 0.0f, 1.0f), // A: Red
FLinearColor(1.0f, 0.5f, 0.0f, 1.0f), // B: Orange
FLinearColor(1.0f, 1.0f, 0.0f, 1.0f), // C: Yellow
FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), // D: Green
FLinearColor(0.0f, 0.0f, 1.0f, 1.0f), // E: Blue
FLinearColor(0.5f, 0.0f, 1.0f, 1.0f), // F: Indigo
FLinearColor(1.0f, 0.0f, 1.0f, 1.0f), // G: Violet
FLinearColor(1.0f, 0.0f, 0.5f, 1.0f), // H: Purple
FLinearColor(0.5f, 0.0f, 0.5f, 1.0f), // I: Mauve
FLinearColor(0.0f, 0.5f, 0.5f, 1.0f), // J: Teal
FLinearColor(0.5f, 0.5f, 0.5f, 1.0f), // K: Gray
FLinearColor(0.5f, 0.0f, 0.0f, 1.0f), // L: Maroon
FLinearColor(0.0f, 0.5f, 0.0f, 1.0f), // M: Lime
FLinearColor(0.0f, 0.5f, 0.5f, 1.0f), // N: Aqua
FLinearColor(0.5f, 0.5f, 0.0f, 1.0f), // O: Olive
FLinearColor(0.0f, 0.0f, 0.5f, 1.0f), // P: Navy
FLinearColor(0.5f, 0.0f, 0.5f, 1.0f), // Q: Fuchsia
FLinearColor(0.5f, 1.0f, 0.0f, 1.0f), // R: Chartreuse
FLinearColor(0.0f, 0.5f, 1.0f, 1.0f), // S: Sky Blue
FLinearColor(1.0f, 0.5f, 0.5f, 1.0f), // T: Salmon
FLinearColor(0.5f, 0.0f, 0.0f, 1.0f), // U: Burgundy
FLinearColor(0.0f, 0.0f, 0.0f, 1.0f), // V: Black
FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), // W: White
FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), // X: Cyan
FLinearColor(0.5f, 0.5f, 1.0f, 1.0f), // Y: Lavender
FLinearColor(0.75f, 0.75f, 0.0f, 1.0f) // Z: Gold
};
int rainbowColorIndex = static_cast<int>(fmod(cnt * rainbowSpeed, 7.0f));
FLinearColor color1 = rainbowColors[rainbowColorIndex];
FLinearColor color2 = rainbowColors[(rainbowColorIndex + 1) % 7]; // Wrap around
float t = fmod(cnt * rainbowSpeed, 1.0f); // Interpolation factor
FLinearColor rainbowColor = FLinearColor(
color1.R + (color2.R - color1.R) * t,
color1.G + (color2.G - color1.G) * t,
color1.B + (color2.B - color1.B) * t,1.0f);
xRGB->HitPerform.HitBodyDrawColor = rainbowColor;   // body hit color
xRGB->HitPerform.HitHeadDrawColor = rainbowColor;  // head hoit color
if (cnt >= 360.0f) {
cnt = 0.0f;
}else {
cnt += 0.02f;
}}}}}
auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
}
return 0;
}

[[noreturn]]
void * kaushik4_thread(void *) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer && localController) {

if (SkinxShuit) {
     if (localPlayer -> AvatarComponent2) {
          auto AvatarComp = localPlayer -> AvatarComponent2;
          FNetAvatarSyncData NetAvatarComp = * (FNetAvatarSyncData * )((uintptr_t) AvatarComp + 0x388);
          auto Slotsybc = NetAvatarComp.SlotSyncData;
          	
	
	 Slotsybc[5].ItemId =  1406891;//Fiore X-Suit (7-Star)
	 Slotsybc[8].ItemId =  1501003443;//bag
}}}

auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
}
return 0;
}

/*
 *  @date   : 2020/02/04
 *  @Creator : @Mrkaushikhaxor
 *  Prince Kaushik
 */
 
 /*
[[noreturn]]
void * kaushik4_thread(void *) {
while (true) {
auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
auto localPlayer = g_LocalPlayer;
auto localController = g_LocalController;
if (localPlayer && localController) {

if (SkinxShuit) {
     if (localPlayer -> AvatarComponent2) {
          auto AvatarComp = localPlayer -> AvatarComponent2;
          FNetAvatarSyncData NetAvatarComp = * (FNetAvatarSyncData * )((uintptr_t) AvatarComp + 0x388);
          auto Slotsybc = NetAvatarComp.SlotSyncData;
       
     //Slotsybc[5].ItemId =  1407103;//Fiore X-Suit (7-Star)
	 Slotsybc[5].ItemId =  1406891;//Psychophage Set
	 Slotsybc[8].ItemId =  1501003443;//bag
	 Slotsybc[9].ItemId = 1502003023;//Glacier Helmet (Lv. 3)
		// localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
	
	 }}
	 

}auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
}
return 0;
}
*/
#include "Includes/bypass.h"
#include "Includes/Egl.h"
