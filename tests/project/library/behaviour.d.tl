local interface Behaviour
    string_name: string

    init: function(self)
    update: function(self, number)
    late_update: function(self, number)
    fixed_update: function(self, number)
    on_render: function(self)
    on_gui: function(self)
    exit: function(self)
end

return Behaviour
