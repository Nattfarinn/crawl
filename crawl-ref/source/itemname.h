/*
 *  File:       itemname.h
 *  Summary:    Misc functions.
 *  Written by: Linley Henzell
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 */


#ifndef ITEMNAME_H
#define ITEMNAME_H

#include "externs.h"

struct item_types_pair
{
    object_class_type base_type;
    unsigned char     sub_type;
};

enum item_type_id_type
{
    IDTYPE_WANDS = 0,
    IDTYPE_SCROLLS,
    IDTYPE_JEWELLERY,
    IDTYPE_POTIONS,
    IDTYPE_STAVES,
    NUM_IDTYPE
};

// [dshaligram] If you edit potion colours/descriptions, also update
// itemname.cc.
enum potion_description_colour_type
{
    PDC_CLEAR,
    PDC_BLUE,
    PDC_BLACK,
    PDC_SILVERY,
    PDC_CYAN,
    PDC_PURPLE,
    PDC_ORANGE,
    PDC_INKY,
    PDC_RED,
    PDC_YELLOW,
    PDC_GREEN,
    PDC_BROWN,
    PDC_PINK,
    PDC_WHITE,
    PDC_NCOLOURS
};

// [dshaligram] If you edit potion colours/descriptions, also update
// itemname.cc.
enum potion_description_qualifier_type
{
    PDQ_NONE,
    PDQ_BUBBLING,
    PDQ_FUMING,
    PDQ_FIZZY,
    PDQ_VISCOUS,
    PDQ_LUMPY,
    PDQ_SMOKY,
    PDQ_GLOWING,
    PDQ_SEDIMENTED,
    PDQ_METALLIC,
    PDQ_MURKY,
    PDQ_GLUGGY,
    PDQ_OILY,
    PDQ_SLIMY,
    PDQ_EMULSIFIED,
    PDQ_NQUALS
};

bool is_vowel( const char chr );

/* ***********************************************************************
 * called from: debug - describe - dungeon - fight - files - item_use -
 *              monstuff - mstuff2 - players - spells0
 * *********************************************************************** */
int property( const item_def &item, int prop_type );

/* ***********************************************************************
 * called from: describe
 * *********************************************************************** */
const char* racial_description_string(const item_def& item, bool terse = false);

/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void check_item_knowledge();

std::string quant_name( const item_def &item, int quant,
                        description_level_type des, bool terse = false );

bool item_type_known( const item_def &item );
bool item_type_known( const object_class_type base_type, const int sub_type );
bool item_type_tried( const item_def &item );

bool is_interesting_item( const item_def& item );
bool is_emergency_item( const item_def& item );
bool is_good_item(const item_def &item);
bool is_bad_item(const item_def &item, bool temp = false);
bool is_dangerous_item( const item_def& item, bool temp = false);
bool is_useless_item(const item_def &item, bool temp = false);

std::string make_name( unsigned long seed, bool all_caps );

const char* weapon_brand_name(const item_def& item, bool terse);

/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void init_properties();

typedef FixedArray < item_type_id_state_type, NUM_IDTYPE, 50 > id_arr;

id_arr& get_typeid_array();
item_type_id_state_type get_ident_type(const item_def &item);
item_type_id_state_type get_ident_type(object_class_type basetype,
                                       int subtype);
void set_ident_type( item_def &item, item_type_id_state_type setting,
                     bool force = false);
void set_ident_type( object_class_type basetype, int subtype,
                     item_type_id_state_type setting, bool force = false);

/* ***********************************************************************
 * called from: command - itemname - invent.h
 * *********************************************************************** */
const std::string menu_colour_item_prefix(const item_def &item,
                                          bool temp = true);
const std::string get_menu_colour_prefix_tags(item_def &item,
                                              description_level_type desc);
const std::string get_message_colour_tags(item_def &item,
                                          description_level_type desc,
                                          msg_channel_type channel = MSGCH_PLAIN);

void            init_item_name_cache();
item_types_pair item_types_by_name(std::string name);

std::vector<std::string> item_name_list_for_glyph(unsigned glyph);

/* ***********************************************************************
 * called from: newgame
 * *********************************************************************** */
const char* wand_type_name(int wandtype);

#endif
