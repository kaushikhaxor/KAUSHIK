function HOME()
local file = io.open("Extra_Offset_Bgmi_64.cpp", "w")
file:write("/*\n")
file:write("   √ Created By: Kaushik | @MrKaushikhaxor\n")
file:write("   √ Join Telegram: @KaushikCracking\n")
file:write("   √ Need Help? DM: @MrKaushikhaxor\n")
file:write("   √ Pattern & Support By: @MrKaushikhaxor\n")
file:write("   √ Simple & Easy — No Updates Needed\n")
file:write("   √ Click 'OK' to Start the Process\n")
file:write("   💲 Buy Now: @MrKaushikhaxor\n")
file:write("*/\n")

file:write("\n")
file:write("\n")
file:write("/* BGMI - 64 - BY - KAUSHIK*/\n")

local combined_message = [[
√ Created By: @MrKaushikhaxor  
√ Easy to Use - No Need Update
√ No Updates Required  
√ Join : @KaushikCracking  
√ Tap Ok Start with Kaushik  
💲Purchase : @MrKaushikhaxor
]]

gg.alert(combined_message)



local haxor_output = nil
local haxor1_output = nil
local haxor2_output = nil
local haxor3_output = nil
local haxor4_output = nil


gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP | gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("-484,675,645,209,532,272;-7,984,633,576,798,413,295", gg.TYPE_QWORD)
gg.refineNumber("-484,675,645,209,532,272", gg.TYPE_QWORD)
if gg.getResultCount() == 0 then
    haxor_output = "Value not found \nStrlen_Offset"
else
    local Kaushik = gg.getResults(1)
    gg.clearResults()
    local time = gg.getRangesList("libUE4.so")[1].start
    local Kaushikoff = Kaushik[1].address - time - 0
    haxor_output = string.format("#define Strlen_Offset 0x%x", Kaushikoff)
    file:write(""..haxor_output.."\n")
end


gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP | gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("-485,163,828,372,264,816", gg.TYPE_QWORD)
if gg.getResultCount() == 0 then
    haxor1_output = "Value not found \nSwapBuffers_Offset"
else
    local Kaushik = gg.getResults(1)
    gg.clearResults()
    local time = gg.getRangesList("libUE4.so")[1].start
    local Kaushikoff = Kaushik[1].address - time - 0
    haxor1_output = string.format("#define SwapBuffers_Offset 0x%x", Kaushikoff)
    file:write(""..haxor1_output.."\n")
end


gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP | gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("-6,268,311,401,282,862,081;-5,116,058,520,558,290,552", gg.TYPE_QWORD)
gg.refineNumber("-6268311401282862081", gg.TYPE_QWORD)

if gg.getResultCount() == 0 then
    haxor2_output = "Value not found \nShootEvent_Offset"
else
    local Kaushik = gg.getResults(1)
    gg.clearResults()
    local time = gg.getRangesList("libUE4.so")[1].start
    local Kaushikoff = Kaushik[1].address - time - 0
    haxor2_output = string.format("#define ShootEvent_Offset 0x%x", Kaushikoff)
    file:write(""..haxor2_output.."\n")
end

gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP | gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("-6,268,311,401,282,845,697;-6,196,948,733,624,484,225", gg.TYPE_QWORD)
gg.refineNumber("-6,268,311,401,282,845,697", gg.TYPE_QWORD)
if gg.getResultCount() == 0 then
    haxor3_output = "Value not found \nGetCameraTransform_Offset"
else
    local Kaushik = gg.getResults(1)
    gg.clearResults()
    local time = gg.getRangesList("libUE4.so")[1].start
    local Kaushikoff = Kaushik[1].address - time - 0
    haxor3_output = string.format("#define GetCameraTransform_Offset 0x%x", Kaushikoff)
    file:write(""..haxor3_output.."\n")
end


gg.clearResults()
gg.setRanges(gg.REGION_CODE_APP | gg.REGION_C_DATA | gg.REGION_C_BSS)
gg.searchNumber("-216,071,709,436,607,489;-486,098,383,174,138,883", gg.TYPE_QWORD)
gg.refineNumber("-216,071,709,436,607,489", gg.TYPE_QWORD)


if gg.getResultCount() == 0 then
    haxor4_output = "Value not found \nUpdateVolley_Offset"
else
    local Kaushik = gg.getResults(1)
    gg.clearResults()
    local time = gg.getRangesList("libUE4.so")[1].start
    local Kaushikoff = Kaushik[1].address - time - 0
    haxor4_output = string.format("#define UpdateVolley_Offset 0x%x", Kaushikoff)
    file:write(""..haxor4_output.."\n")
end

-- Combined Alert
local combined_alert = haxor_output .. "\n"  .. haxor1_output .. "\n" .. haxor2_output .. "\n" .. haxor3_output .. "\n" .. haxor4_output
gg.alert(combined_alert)

file:write("#define ShortEvent_Offset 169 // Idx Not Sure\n")
file:write("#define UpdateVolley_Offset 157 // Idx Not Sure\n")

file:write("/* 𝙂𝙚𝙣𝙚𝙧𝙖𝙩𝙚𝙙 𝘽𝙮 𝙆𝙖𝙪𝙨𝙝𝙞𝙠 ! 𝘽𝙪𝙮 - @𝙈𝙧𝙠𝙖𝙪𝙨𝙝𝙞𝙠𝙝𝙖𝙭𝙤𝙧 */\n")
file:write("\n")
file:write("\n")
file:write("\n")
file:write("/*--------------------------------------------------------------------------------------------------------------------------------------- \n")
file:write("-- Credit - @Mrkauahikhaxor \n")
file:write("-- Without Credit Sucks My Dick\n")
file:write("⠀⠀⠀⣴⣾⣿⣿⣶⡄⠀                     \n")
file:write("⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠈⢿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠈⣉⣩⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⣼⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⢀⣼⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⢀⣾⣿⣿⣿⣿⣿⣿⣷⠀ ⠀⠀⠀⠀⠀⠀.          \n")
file:write("⢠⣾⣿⣿⠉⣿⣿⣿⣿⣿⡄⠀⢀⣠⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠙⣿⣿⣧⣿⣿⣿⣿⣿⡇⢠⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣷⠸⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠘⠿⢿⣿⣿⣿⣿⡄⠙⠻⠿⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⠀⡟⣩⣝⢿⠀⠀⣠⣶⣶⣦⡀⠀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⠀⣷⡝⣿⣦⣠⣾⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣮⢻⣿⠟⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⠻⠿⠻⣿⣿⣿⣿⣦⡀⠀⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⠇⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡆⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⠇⠀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⢸⣿⣿⡿⠀⠀⠀⢀⣴⣿⣿⣿⣿⣟⣋⣁⣀⣀⠀\n")
file:write("⠀⠀⠀⠀⠀⠀⠹⣿⣿⠇⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n")
file:write("-------------KAUSHIK --- Copy Paster-------------\n")
file:write("---------------------------------------------------------------------------------------------------------------------------------------*/\n")


file:close()
gg.alert("Offsets and information written to Extra_Offset_Bgmi_64.cpp")
end

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ExIt
function EXIT()
print("✓ Created By - @Mrkaushikhaxor")
print("✓ Join Telegram @KaushikCracking")
gg.skipRestoreState()
gg.setVisible(true)
os.exit()
end

cs = "21"
while true do
if gg.isVisible(true) then
KAUSHIKHAXOR = 1
gg.setVisible(false)
end
if KAUSHIKHAXOR == 1 then
HOME()
EXIT()
end
end