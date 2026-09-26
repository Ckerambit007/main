ServerEvents.tags('item', event => {
    // Удаляем слиток из всех возможных тегов чугуна
    event.get('createbigcannons:ingot_cast_iron').remove('createbigcannons:cast_iron_ingot')
    event.get('c:ingots/cast_iron').remove('createbigcannons:cast_iron_ingot')
    event.get('forge:ingots/cast_iron').remove('createbigcannons:cast_iron_ingot')

    // Удаляем самородок
    event.get('createbigcannons:nugget_cast_iron').remove('createbigcannons:cast_iron_nugget')
    event.get('c:nuggets/cast_iron').remove('createbigcannons:cast_iron_nugget')
    event.get('forge:nuggets/cast_iron').remove('createbigcannons:cast_iron_nugget')

    // Удаляем блок
    event.get('createbigcannons:block_cast_iron').remove('createbigcannons:cast_iron_block')
    event.get('c:storage_blocks/cast_iron').remove('createbigcannons:cast_iron_block')
    event.get('forge:storage_blocks/cast_iron').remove('createbigcannons:cast_iron_block')
})
ServerEvents.tags('item', event => {
    // Удаляем стальной слиток из всех возможных тегов
    event.get('createbigcannons:ingot_steel').remove('createbigcannons:steel_ingot')
    event.get('c:ingots/steel').remove('createbigcannons:steel_ingot')
    event.get('forge:ingots/steel').remove('createbigcannons:steel_ingot')
    event.get('c:steel_ingots').remove('createbigcannons:steel_ingot')

    // Удаляем стальной блок
    event.get('createbigcannons:block_steel').remove('createbigcannons:steel_block')
    event.get('c:storage_blocks/steel').remove('createbigcannons:steel_block')
    event.get('forge:storage_blocks/steel').remove('createbigcannons:steel_block')
    event.get('c:steel_blocks').remove('createbigcannons:steel_block')

    // Удаляем стальной лом
    event.remove('c:nuggets/steel', 'createbigcannons:steel_scrap')
    event.remove('forge:nuggets/steel', 'createbigcannons:steel_scrap')
    event.remove('c:steel_nuggets', 'createbigcannons:steel_scrap')
})
ServerEvents.tags('item', event => {

    // Copper Wire
    event.get('forge:wires/copper').remove('createaddition:copper_wire')
    event.get('forge:wires').remove('createaddition:copper_wire')
    event.get('c:wires/copper').remove('createaddition:copper_wire')
    event.get('c:copper_wires').remove('createaddition:copper_wire')
    event.get('c:wires').remove('createaddition:copper_wire')

    // Iron Wire
    event.get('forge:wires/iron').remove('createaddition:iron_wire')
    event.get('forge:wires').remove('createaddition:iron_wire')
    event.get('c:wires/iron').remove('createaddition:iron_wire')
    event.get('c:iron_wires').remove('createaddition:iron_wire')
    event.get('c:wires').remove('createaddition:iron_wire')

    // Gold Wire
    event.get('forge:wires/gold').remove('createaddition:gold_wire')
    event.get('forge:wires').remove('createaddition:gold_wire')
    event.get('c:wires/gold').remove('createaddition:gold_wire')
    event.get('c:gold_wires').remove('createaddition:gold_wire')
    event.get('c:wires').remove('createaddition:gold_wire')

    // Electrum Wire
    event.get('c:wires/electrum').remove('createaddition:electrum_wire')
    event.get('c:electrum_wires').remove('createaddition:electrum_wire')
    event.get('c:wires').remove('createaddition:electrum_wire')
})
ServerEvents.tags('item', event => {

    // Zinc Sheet
    event.get('forge:plates/zinc').remove('createaddition:zinc_sheet')
    event.get('c:plates/zinc').remove('createaddition:zinc_sheet')
    event.get('c:zinc_plates').remove('createaddition:zinc_sheet')

})