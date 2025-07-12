gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("3,974,362,539,628,152,236;17,179,869,188", gg.TYPE_QWORD)
gg.refineNumber("17,179,869,188", gg.TYPE_QWORD)
fuck = gg.getResults(1)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff = fuck[1].address - time - 0x8
local output = string.format("%x", fuckoff)
print("Gname Offsets: 0x"..output.."")



--GWorld Java
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_BSS)
gg.searchNumber("17,179,869,188;38,654,705,664", gg.TYPE_QWORD)
gg.refineNumber("17,179,869,188", gg.TYPE_QWORD)
fuck = gg.getResults(5)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff = fuck[2].address - time + 40
local output = string.format("%x", fuckoff)
print("GWorld Offsets: 0x"..output.."")



--VMatrix
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_BSS)
gg.searchNumber("16,384;90.0F", gg.TYPE_DWORD)
gg.refineNumber("90.0", gg.TYPE_FLOAT)
fuck = gg.getResults(1)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time + 20
local output = string.format("%x", fuckoff)
print("VMatrix Offsets: 0x"..output.."")



--Vworld/CanvasMap
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_BSS)
gg.searchNumber("17179869186;12884901892;3:9", gg.TYPE_QWORD)
gg.refineNumber("3", gg.TYPE_QWORD)
fuck = gg.getResults(3)
gg.clearResults()
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[3].address - time - 16
local output = string.format("%x", fuckoff)
print("Vworld Offsets: 0x"..output.."\n")



--GNames Sdk
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.setVisible(false)
gg.searchNumber("h 02 00 00 14 E8 03 1F 2A 68 1E 10 79")
gg.refineNumber("h 79")
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time + 25
local output = string.format("%x", fuckoff)
print("#define GNames_Offset 0x"..output.."")


--GEngine_Offset
gg.clearResults()
gg.setRanges(gg.REGION_C_BSS)
gg.setVisible(false)
gg.searchNumber("2.2958874e-41;90.0", gg.TYPE_FLOAT)
gg.refineNumber("90.0", gg.TYPE_FLOAT)
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff = fuck[1].address - time + 20
local output = string.format("%x", fuckoff)
print("#define GEngine_Offset 0x"..output.." //UEngine")



--GEngine LocalPlayer
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_BSS)
gg.searchNumber("16,384;90.0F", gg.TYPE_DWORD)
gg.refineNumber("90.0F", gg.TYPE_DWORD)
fuck = gg.getResults(1)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time + 0xC - 4
local output = string.format("%x", fuckoff)
print("#define GEngine_Offset 0x"..output.." //ULocalPlayer")



--GUObjectArray
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("480,000;0;16,384:17", gg.TYPE_DWORD)
gg.refineNumber("480,000", gg.TYPE_DWORD)
fuck = gg.getResults(1)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time  - 24
local output = string.format("%x", fuckoff)
print("#define GUObject_Offset 0x"..output.."")

--GetActorArrary
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.searchNumber("-1,455,337,484;-1,463,649,283;335,544,950;-1,447,134,211", gg.TYPE_DWORD)
gg.refineNumber("-1,447,134,211", gg.TYPE_DWORD)
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[5].address - time
local output = string.format("%x", fuckoff)
print("#define GetActorArray_Offset 0x"..output.."")

--CanvasMap
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_C_BSS)
gg.searchNumber("17179869186;12884901892;3:9", gg.TYPE_QWORD)
gg.refineNumber("3", gg.TYPE_QWORD)
fuck = gg.getResults(3)
gg.clearResults()
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[3].address - time - 16
local output = string.format("%x", fuckoff)
print("#define CanvasMap_Offset 0x"..output.."")

--Kill Message
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.searchNumber("-6,263,002,989,878,550,532;-6,262,730,319,584,733,194;-7,997,051,544,072,204,300:9", gg.TYPE_QWORD)
gg.refineNumber("-7,997,051,544,072,204,300", gg.TYPE_QWORD)
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[3].address - time - 16
local output = string.format("%x", fuckoff)
print("#define KillMessage_Offset 0x"..output.."")

--ProcessEvent_Offset Child
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.searchNumber("-6,268,069,539,460,521,992;-5,080,047,147,011,832,920;-486,378,680,650,560,504;-5,098,042,712,070,813,398:49", gg.TYPE_QWORD)
gg.refineNumber("-6,268,069,539,460,521,992", gg.TYPE_QWORD)
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time  - 8
local output = string.format("%x", fuckoff)
print("#define ProcessEvent_Offset 0x"..output.." //Child")

--ProcessEvent Main
gg.clearResults()
gg.setVisible(false)
gg.setRanges(gg.REGION_CODE_APP)
gg.searchNumber("-7,998,388,550,212,890,636;-486,388,722,963,577,859;-1,152,380,364,610,600,952:9", gg.TYPE_QWORD)
gg.refineNumber("-1,152,380,364,610,600,952", gg.TYPE_QWORD)
fuck = gg.getResults(1)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time - 16
local output = string.format("%x", fuckoff)
print("#define ProcessEvent_Offset 0x"..output.." //Main")


--GNativeAndroidApp
gg.clearResults()
gg.setRanges(gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.setVisible(false)
gg.searchNumber("h 5D 02 00 00 00 00 00 00 01 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 01 00 00 00")
gg.refineNumber("h 5D")
fuck = gg.getResults(20)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time - 0x58
local output = string.format("%x", fuckoff)
print("#define GNativeAndroidApp_Offset 0x"..output.."")



--Actors Offset
gg.clearResults()
gg.setRanges(gg.REGION_C_DATA)
gg.searchNumber("64;560;560;21", gg.TYPE_DWORD)
gg.refineNumber("21", gg.TYPE_DWORD)
fuck = gg.getResults(20)
gg.clearResults()
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[2].address - time
local output = string.format("%x", fuckoff)
print("#define Actors_Offset 0x"..output.."")



--PostRer_Offset
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.setVisible(false)
gg.searchNumber("706,675,680;-1,862,269,955;960,614,408:21",gg.TYPE_DWORD)--4,294,967,296;4,294,967,297;2,598,455,214,081;605
gg.refineNumber("960,614,408",gg.TYPE_DWORD)
fuck = gg.getResults(21)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time - 12
local output = string.format("%x", fuckoff)
print("#define PostRer_Offset 0x"..output.."")



--K2_DrawLine
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.setVisible(false)
gg.searchNumber("-1,459,192,835;-1,862,171,651;505,428,037:9",gg.TYPE_DWORD)--4,294,967,296;4,294,967,297;2,598,455,214,081;605
gg.refineNumber("505,428,037",gg.TYPE_DWORD)
fuck = gg.getResults(21)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time - 12
local output = string.format("%x", fuckoff)
--gg.copyText("0x"..output.."")
print("#define K2_DrawLine_Offset 0x"..output.."")


--K2_DrawTexture
gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP)
gg.setVisible(false)
gg.searchNumber("1,833,581,551;-1,862,007,809;1,828,922,345:25",gg.TYPE_DWORD)--4,294,967,296;4,294,967,297;2,598,455,214,081;605
gg.refineNumber("1,828,922,345",gg.TYPE_DWORD)
fuck = gg.getResults(21)
gg.clearResults()
gg.setVisible(false)
time = gg.getRangesList("libUE4.so")[1].start
fuckoff =  fuck[1].address - time  - 26
local output = string.format("%x", fuckoff)
gg.copyText("0x"..output.."")
print("#define K2_DrawTexture_Offset 0x"..output.."")

local Bykaushik = ""
print("\n Generated By : @By_Kaushik"..Bykaushik.."")
