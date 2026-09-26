ServerEvents.recipes(event => {

    // Copper Wire
    event.remove({ output: 'electroenergetics:copper_wire' })

    event.custom({
        type: 'createaddition:rolling',
        ingredients: [
            { item: 'create:copper_sheet' }
        ],
        results: [
            {
                id: 'electroenergetics:copper_wire',
                count: 2
            }
        ]
    })

    // Iron Wire
    event.remove({ output: 'electroenergetics:iron_wire' })

    event.custom({
        type: 'createaddition:rolling',
        ingredients: [
            { item: 'create:iron_sheet' }
        ],
        results: [
            {
                id: 'electroenergetics:iron_wire',
                count: 2
            }
        ]
    })

    // Electrum Wire
    event.remove({ output: 'electroenergetics:electrum_wire' })

    event.custom({
        type: 'createaddition:rolling',
        ingredients: [
            { item: 'createaddition:electrum_sheet' }
        ],
        results: [
            {
                id: 'electroenergetics:electrum_wire',
                count: 2
            }
        ]
    })

    // Gunpowder
    event.remove({ id: 'tfmg:mixing/gunpowder' })

    event.recipes.create.mixing(
        Item.of('minecraft:gunpowder', 6),
        [
            '3x tfmg:nitrate_dust',
             Ingredient.of('minecraft:charcoal').or('minecraft:coal'),
             Ingredient.of('minecraft:charcoal').or('minecraft:coal'),
            'tfmg:sulfur_dust'
        ]
    )

    // Pocker
    event.remove({ id: 'create_ultimate_factory:mixing_gunpowder' })

    event.recipes.create.mixing(
        'minecraft:gunpowder',
        [
            'minecraft:blaze_powder',
             Ingredient.of('minecraft:charcoal').or('minecraft:coal'),
             Ingredient.of('minecraft:charcoal').or('minecraft:coal')
        ]
    )

    // Sulfur
    event.recipes.create.milling(
        [
            CreateItem.of('tfmg:sulfur_dust', 0.6)
        ],
        'minecraft:magma_cream'
    )
   
    
    // Wrench
    event.remove({ output: 'pipez:wrench' })

    event.shaped(
        'pipez:wrench',
        [
            ' A ',
            ' BA',
            'B  '
        ],
        {
            A:'minecraft:flint',
            B:'minecraft:stick'
        }
    )

    //Tesla
    event.remove({ output: 'createaddition:tesla_coil' })

    event.recipes.create.mechanical_crafting(
        'createaddition:tesla_coil',
        [
            'AAA',
            ' B ',
            'CDC',
            'EFE'
        ],
        {
            A: 'electroenergetics:copper_wire_spool',
            B: 'create:andesite_alloy',
            C: 'electroenergetics:capacitor',
            D: 'create:brass_casing',
            E: 'create:brass_sheet',
            F: 'create:electron_tube'
        }
    )



})
   