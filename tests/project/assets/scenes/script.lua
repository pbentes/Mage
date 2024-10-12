---@class Player: Behaviour
local player = Behaviour:new()

player.j = 10

function player:update (delta)
    if not delta == nil then
        self.k = delta
    end
    self.j = self.j + 1
end

return player