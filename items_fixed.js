ServerEvents.recipes(event => {
    // Удаляем рецепт по выходному предмету
    event.remove({ output: 'createbigcannons:cast_iron_ingot' });
    
    event.remove({ output: 'createbigcannons:cast_iron_nugget' });

    event.remove({ output: 'createbigcannons:cast_iron_block' });

    event.remove({ output: 'createbigcannons:steel_ingot' });

    event.remove({ output: 'createbigcannons:steel_block' });

    event.remove({ output: 'createbigcannons:steel_scrap' });

    event.remove({ output: 'createaddition:iron_rod' });

    event.remove({ output: 'createaddition:gold_rod' });

    event.remove({ output: 'createaddition:electrum_rod' });

    event.remove({ output: 'createaddition:copper_rod' });

    event.remove({ output: 'createaddition:brass_rod' });

    event.remove({ output: 'createaddition:iron_wire' });

    event.remove({ output: 'createaddition:gold_wire' });

   event.remove({ output: 'createaddition:electrum_wire' });

   event.remove({ output: 'createaddition:copper_wire' });

});
ServerEvents.recipes(event => {
    event.remove({ id: 'createbigcannons:mixing/alloy_nethersteel_cast_iron' })
})
ServerEvents.recipes(event => {
    event.remove({ id: 'createbigcannons:compacting/forge_nethersteel_ingot' })
    event.remove({ id: 'createbigcannons:compacting/forge_nethersteel_nugget' })
})
ServerEvents.recipes(event => {
    event.remove({ id: 'cgs:gunpowder' })
    event.remove({ id: 'tfmg:mixing/gunpowder' })
})