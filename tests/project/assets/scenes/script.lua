local public = Behaviour:new()

public.j = 10

function public:update (delta)
    self.j = self.j + 1
end

return public