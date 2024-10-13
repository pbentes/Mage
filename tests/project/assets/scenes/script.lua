---@class Player: Behaviour
Player = Behaviour:new()

local k = 120

---@type number
Player.j = 10

function Player:update(delta)
    print("Player1:", Entity1_Player.j)
    k = k + 1

    self.j = self.j + 1
    print(self.j)
end