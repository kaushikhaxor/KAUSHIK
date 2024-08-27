-- Source By @Mrkaushikhaxor
-- Edit By KAUSHIK
-- Use With Credits Dont Remove This .
gg.alert("Tool By @Mrkaushikhaxor\nNot Supported For All Lua Scripts") 
local g = {}
g.last = gg.getFile()
g.info = nil
g.config = gg.getFile():gsub('%lua$', '')..'cfg'
g.data = loadfile(g.config)
if g.data ~= nil then
	g.info = g.data()
	g.data = nil
end
if g.info == nil then
	g.info = {g.last, g.last:gsub('/[^/]+$', ''), nil}
end
if g.info[3] == nil then g.info[3] = gg.VERSION end
while true do
	g.info = gg.prompt({'Select Script To Hook :-', 'Select Output Of Hook :-',
		'GameGuardian Version', 'Hook Script'}, g.info, {'file', 'path', 'text', 'checkbox'})
	if g.info == nil then break end
	gg.saveVariable(g.info, g.config)
	gg.VERSION = g.info[3]
	gg.VERSION_INT = tonumber((gg.VERSION:gsub('%.[0-9]+', function (m)
		m = m:sub(2)
		if #m == 1 then m = '0'..m end
		return m
	end)))
	g.last = g.info[1]                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       --SG                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	g.test = loadfile(g.last)
	g.loaded = g.last
	if g.test == nil then
		gg.alert('Failed load script: '..g.last)
	else
		g.name = g.last:match('[^/]+$')
		g.pathes = {g.info[2]:gsub('/?$', '')..'/'..g.name, g.last, '/sdcard/'..g.name, gg.getFile():gsub('[^/]+$', '')..g.name, gg.EXT_FILES_DIR..'/'..g.name}
		g.file = nil
		g.out = ''
		g.try = ''
		for i, v in ipairs(g.pathes) do
			g.out = v..".tmp.lua"
			g.file = io.open(g.out, "w")
 			if g.file ~= nil then
 				g.last = v:gsub('%.lua$', '')
 				break
			end
			g.try = g.try..' '..v
		end
		if g.file == nil then
			gg.alert('Failed write to file. Checked:'..g.try)
		else
			g.file:close()
			os.remove(g.out)
			
			if g.info[4] then
				if true then
					local ggg = {}
					for k, v in pairs(gg) do
						ggg[k] = v
					end
					local sel = select
					local typ = type
					local str = tostring
					local echo = print
					local io_open = io.open
					local tr = {}
					local slen = string.len
					
					local msg = ''
					local rnd = g.last..'.KAUSHIK'
						local file = rnd..'.lua'
						local f = io_open(file, 'wb')
						f:write("--▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n-- Hook Started\n-- Tool By @Mrkaushikhaxor \n--▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n\n")
						f:close()
						local names = {
							allocatePage = {'^PROT_', '0x%X'},
							copyMemory = {'0x%X', '0x%X'},
							dumpMemory = {'0x%X', '0x%X'},
							gotoAddress = {'0x%X'},
							setRanges = {'^REGION_'},
							searchNumber = {nil, '^TYPE_', nil, '^SIGN_[^F]', '0x%X', '0x%X'},
							refineNumber = {nil, '^TYPE_', nil, '^SIGN_[^F]', '0x%X', '0x%X'},
							startFuzzy = {'^TYPE_', '0x%X', '0x%X'},
							searchFuzzy = {nil, '^SIGN_FUZZY_', '^TYPE_', '0x%X', '0x%X'},
							searchAddress = {nil, '0x%X', '^TYPE_', '^SIGN_[^F]', '0x%X', '0x%X'},
							refineAddress = {nil, '0x%X', '^TYPE_', '^SIGN_[^F]', '0x%X', '0x%X'},
							getResults = {nil, nil, '0x%X', '0x%X', nil, nil, '^TYPE_', nil, '^POINTER_'},
							editAll = {nil, '^TYPE_'},
							loadList = {nil, '^LOAD_'},
							saveList = {nil, '^SAVE_'},
						}
						names.refineAddress = names.searchAddress
						names.refineNumber = names.searchNumber
						local rets = {
							alert = 1,
							prompt = 1,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                --SG
							choice = 1,
							multiChoice = 1,
						}
						local smatch = string.match
						local ssub = string.sub
						local sformat = string.format
						local toFlags = function (check, value)
							local ret = ''
							for k, v in pairs(ggg) do
								if smatch(k, check) ~= nil and (value & v) == v then
									if ret ~= '' then ret = ret..' | ' end
									ret = ret..'gg.'..k
									value = value & ~v
								end
							end
							if ret == '' or value ~= 0 then
								if ret ~= '' then ret = ret..' | ' end
								ret = ret..value
							end
							return ret
						end
						for i, v in pairs(ggg) do
							if typ(v) == 'function' and i ~= 'getFile' and i ~= 'getLine' and i ~= 'isVisible' then
								local orig = v
								local name = i
								local hook = 1
								hook = function (...)
									local arg = {...}
									local f = io_open(file, 'ab')
									f:write('gg.'..name..'(')
									for j, a in ipairs(arg) do
										if j ~= 1 then f:write(', ') end
										if typ(a) == 'string' then f:write('"') end
										local b = a
										if typ(a) == 'number' and names[name] ~= nil and names[name][j] ~= nil then
											local check = names[name][j]
											if ssub(check, 1, 1) ~= '^' then
												if a == 0 or a == -1 then
													b = a
												else
													b = sformat(check, a)
												end
											else
												b = toFlags(check, a)
											end
										end
										b = str(b)
										f:write(b)
										if typ(a) == 'string' then f:write('"') end
									end
									f:write(")")
									if rets[name] ~= nil then
										local ret = orig(...)
										f:write(" --[[ ")
										f:write(str(ret))
										f:write(" ]]\n")
										f:close()
										return ret
									end
									f:write("\n")
									f:close()
									return orig(...)
								end
								tr[hook] = orig
								gg[i] = hook
							end
						end
					end
					if true then
					local ggg = {}
					for k, v in pairs(gg) do
						ggg[k] = v
					end
					local sel = select
					local typ = type
					local str = tostring
					local echo = print
					local io_open = io.open
					local tr = {}
					local slen = string.len
					local echo = print
					local msg = ''
					ggg.alert('Hook Started\nTool By @Mrkaushikhaxor\n'..msg)
					msg = nil
					local tr = {}
					if true then
						local orig = string.dump
						local hook = 1
						hook = function (...)
							local arg = {...}
							if tr[arg[1]] ~= nil then
								--echo('string.dump:', tr[arg[1]], arg[1])
								arg[1] = tr[arg[1]]
							end
							return orig(arg[1], sel(2, ...))
						end
						tr[hook] = orig
						string.dump = hook
					end
					if true then                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 --SG
						local orig = tostring
						local rm = table.remove
						local store = {}
						local build_table = 1
						build_table = function (src, dst)
							local cnt = #store
							store[src] = dst
							for k, v in pairs(src) do
								if tr[v] ~= nil then
									dst[k] = tr[v]
								else
									if typ(v) == 'table' then
										if store[v] ~= nil then
											dst[k] = store[v]
										else
											local bt = {}
											store[v] = bt
											dst[k] = bt
											build_table(v, bt)
										end
									else
										dst[k] = v
									end
								end
							end
							if cnt == 0 then
								while #store > 0 do
									rm(store)
								end
							end
							return dst
						end
						local hook = 1
						hook = function (...)
							local old = tostring
							local arg = {...}
							if tr[arg[1]] ~= nil then
								--tostring = orig; echo('tostring 1:', tr[arg[1]], arg[1]) tostring = old
								arg[1] = tr[arg[1]]
							else
								if typ(arg[1]) == 'table' then
									arg[1] = build_table(arg[1], {})
								end
							end
							local ret = orig(arg[1], sel(2, ...))
							--tostring = orig; echo('tostring 2:', arg[1], ret) tostring = old
							tostring = old
							return ret
						end
						tr[hook] = orig
						tostring = hook
					end
					if false then
						local orig = debug.getupvalue
						local hook = 1
						hook = function (...)
							local arg = {...}
							if tr[arg[1]] ~= nil then
								--echo('debug.getupvalue:', tr[arg[1]], arg[1], arg[2])
								arg[1] = tr[arg[1]]
							end
							return orig(arg[1], sel(2, ...))
						end
						tr[hook] = orig
						debug.getupvalue = hook
					end
					if false then
						local orig = debug.getinfo
						local hook = 1
						hook = function (...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              --SG
							local arg = {...}
							if arg[1] ~= nil and arg[1] > 1 then
								arg[1] = arg[1] + 1
							end
							return orig(arg[1], sel(2, ...))
						end
						tr[hook] = orig
						debug.getinfo = hook
					end
					if false then
						local orig = os.remove
						local hook = 1
						hook = function (...)
							local arg = {...}
							echo('os.remove:', arg)
							return true
						end
						tr[hook] = orig
						os.remove = hook
					end
					if false then
						local orig = assert
						local hook = 1
						hook = function (...)
							local arg = {...}
							echo('assert:', arg)
							return orig(...)
						end
						tr[hook] = orig
						assert = hook
					end
					if false then
						local orig = io.open
						local hook = 1
						hook = function (...)
							local arg = {...}
							echo('io.open:', arg)
							return orig(...)
						end
						tr[hook] = orig
						io.open = hook
					end
				end
				local test = g.test
				g = nil
				return test()
			end
		end
	end
end
--End Tool