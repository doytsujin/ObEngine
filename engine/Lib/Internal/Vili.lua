function vili.array(t)
    local new_node = vili.node.from_type(vili.node_type.array);
    for _, v in pairs(t) do
        new_node:push(vili.node(v));
    end
    return new_node;
end

function vili.object(t)
    local new_node = vili.node.from_type(vili.node_type.object);
    for k, v in pairs(t) do
        new_node:insert(k, vili.node(v));
    end
    return new_node;
end

function vili.from_lua(t)
    return obe.script.vili_lua_bridge.lua_to_vili(t);
end

function vili.to_lua(t)
    return obe.script.vili_lua_bridge.vili_to_lua(t);
end

local function realpath(path)
    local systemPath = obe.system.Path(path);
    local findResult = systemPath:find();
    return findResult:path();
end

function vili.from_file(path, state)
    path = realpath(path)
    state = parser_state or vili.parser.state();
    local node = vili.parser.from_file(path, state);
    return vili.to_lua(node);
end

function vili.from_string(data, parser_state)
    parser_state = parser_state or vili.parser.state();
    local node = vili.parser.from_string(data, parser_state);
    return vili.to_lua(node);
end

function vili.dump(tbl, dump_options)
    dump_options = dump_options or vili.writer.dump_options();
    local node = vili.from_lua(tbl);
    return vili.writer.dump(node, dump_options);
end

function vili.to_file(path, tbl, dump_options)
    dump_options = dump_options or vili.writer.dump_options();
    local node = vili.from_lua(tbl);
    local dump = vili.writer.dump(node, dump_options);
    local dumpfile<close> = io.open(path, "w");
    dumpfile:write(dump);
end
