-- Placeholder for LuaLS code completion

--- @class Vector3
--- @field x number
--- @field y number
--- @field z number
Vector3 = {
    Zero = Vector3:new(0, 0, 0),
    Up = Vector3:new(0, 1, 0),
    Down = Vector3:new(0, -1, 0),
    Right = Vector3:new(1, 0, 0),
    Left = Vector3:new(-1, 0, 0),
    Forwards = Vector3:new(0, 0, 1),
    Backwards = Vector3:new(0, 0, -1)
}

--- @param x number
--- @param y number
--- @param z number
--- @return Vector3
function Vector3:new(x, y, z)
    local obj = {}
    setmetatable(obj, self)
    self.__index = self

    obj.x = x
    obj.y = y
    obj.z = z

    return obj
end