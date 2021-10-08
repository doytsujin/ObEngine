__PATCH_LUA_FUNCTIONS = true;

if not __PATCH_LUA_FUNCTIONS then
    return;
end

local function realpath(path)
    return obe.System.Path(path):find():hypotheticalPath();
end

-- UPL stands for Unpatched Lua Functions
UPL = {
    io = {
        open = io.open,
        popen = io.popen,
    }
};

local io_open = io.open;
function io.open(filename, mode)
    return io_open(realpath(filename), mode);
end

if io.popen then
    local io_popen = io.popen;
    function io.popen(prog, mode)
        return io_popen(realpath(prog), mode);
    end
end