---@class Panel
---@field class string
Panel = {
    class = "Panel"
}

-- Constructor

function Panel:new ()
    local obj = {}
    setmetatable(obj, self)
    self.__index = self
    return obj
end