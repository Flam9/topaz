-----------------------------------
-- Area: Windurst_Woods
-----------------------------------
require("scripts/globals/zone")
-----------------------------------

zones = zones or {}

zones[tpz.zone.WINDURST_WOODS] =
{
    text =
    {
        CONQUEST_BASE                = 0,    -- Tallying conquest results...
        ITEM_CANNOT_BE_OBTAINED      = 6541, -- You cannot obtain the <item>. Come back after sorting your inventory.
        ITEM_OBTAINED                = 6547, -- Obtained: <item>.
        GIL_OBTAINED                 = 6548, -- Obtained <number> gil.
        KEYITEM_OBTAINED             = 6550, -- Obtained key item: <keyitem>.
        KEYITEM_LOST                 = 6551, -- Lost key item: <keyitem>.
        NOT_HAVE_ENOUGH_GIL          = 6552, -- You do not have enough gil.
        YOU_MUST_WAIT_ANOTHER_N_DAYS = 6583, -- You must wait another <number> [day/days] to perform that action.
        CARRIED_OVER_POINTS          = 6586, -- You have carried over <number> login point[/s].
        LOGIN_CAMPAIGN_UNDERWAY      = 6587, -- The [/January/February/March/April/May/June/July/August/September/October/November/December] <number> Login Campaign is currently underway!<space>
        LOGIN_NUMBER                 = 6588, -- In celebration of your most recent login (login no. <number>), we have provided you with <number> points! You currently have a total of <number> points.
        YOU_LEARNED_TRUST            = 6610, -- You learned Trust: <name>!
        HOMEPOINT_SET                = 6638, -- Home point set!
        YOU_ACCEPT_THE_MISSION       = 6731, -- You have accepted the mission.
        PEW_SAHBARAEF_DIALOG         = 6827, -- We can deliver goods to your residence or to the residences of your friends.
        ITEM_DELIVERY_DIALOG         = 6827, -- We can deliver goods to your residence or to the residences of your friends.
        JU_KAMJA_DIALOG              = 6827, -- We can deliver goods to your residence or to the residences of your friends.
        MOG_LOCKER_OFFSET            = 7003, -- Your Mog Locker lease is valid until <timestamp>, kupo.
        FISHING_MESSAGE_OFFSET       = 7101, -- You can't fish here.
        IMAGE_SUPPORT                = 7205, -- Your [fishing/woodworking/smithing/goldsmithing/clothcraft/leatherworking/bonecraft/alchemy/cooking] skills went up [a little/ever so slightly/ever so slightly].
        GUILD_TERMINATE_CONTRACT     = 7219, -- You have terminated your trading contract with the [Fishermen's/Carpenters'/Blacksmiths'/Goldsmiths'/Weavers'/Tanners'/Boneworkers'/Alchemists'/Culinarians'] Guild and formed a new one with the [Fishermen's/Carpenters'/Blacksmiths'/Goldsmiths'/Weavers'/Tanners'/Boneworkers'/Alchemists'/Culinarians'] Guild.
        GUILD_NEW_CONTRACT           = 7227, -- You have formed a new trading contract with the [Fishermen's/Carpenters'/Blacksmiths'/Goldsmiths'/Weavers'/Tanners'/Boneworkers'/Alchemists'/Culinarians'] Guild.
        NO_MORE_GP_ELIGIBLE          = 7234, -- You are not eligible to receive guild points at this time.
        GP_OBTAINED                  = 7239, -- Obtained: <number> guild points.
        NOT_HAVE_ENOUGH_GP           = 7240, -- You do not have enough guild points.
        VALERIANO_SHOP_DIALOG        = 7550, -- Halfling philosophers and heroine beauties, welcome to the Troupe Valeriano show! And how gorgeous and green this fair town is!
        RAKOHBUUMA_OPEN_DIALOG       = 7647, -- To expel those who would subvert the law and order of Windurst Woods... To protect the Mithra populace from all manner of threats and dangers... That is the job of us guards.
        RETTO_MARUTTO_DIALOG         = 7963, -- Allo-allo! If you're after boneworking materials, then make sure you buy them herey in Windurst! We're the cheapest in the whole wide worldy!
        SHIH_TAYUUN_DIALOG           = 7965, -- Oh, that Retto-Marutto... If he keeps carrying on while speaking to the customers, he'll get in trouble with the guildmaster again!
        KUZAH_HPIROHPON_DIALOG       = 7974, -- Sew...I mean...So, want to get your paws on the top-quality materials as used in the Weaverrrs' Guild?
        MERIRI_DIALOG                = 7976, -- If you're interested in buying some works of art from our Weavers' Guild, then you've come to the right placey-wacey.
        PERIH_VASHAI_DIALOG          = 8262, -- You can now become a ranger!
        QUESSE_SHOP_DIALOG           = 8516, -- Welcome to the Windurst Chocobo Stables.
        MONONCHAA_SHOP_DIALOG        = 8517, -- Huh...? If you be wanting anything therrre, [mister/missy], then hurry up and decide, then get the heck out of herrre!
        MANYNY_SHOP_DIALOG           = 8518, -- Are you in urgent needy-weedy of anything? I have a variety of thingy-wingies you may be interested in.
        WIJETIREN_SHOP_DIALOG        = 8523, -- From humble Mithran cold medicines to the legendary Windurstian ambrrrosia of immortality, we have it all...
        NHOBI_ZALKIA_OPEN_DIALOG     = 8526, -- Psst... Interested in some rrreal hot property? From lucky chocobo digs to bargain goods that fell off the back of an airship...all my stuff is a rrreal steal!
        NHOBI_ZALKIA_CLOSED_DIALOG   = 8527, -- You're interested in some cheap shopping, rrright? I'm real sorry. I'm not doing business rrright now.
        NYALABICCIO_OPEN_DIALOG      = 8528, -- Ladies and gentlemen, kittens and cubs! Do we have the sale that you've been waiting forrr!
        NYALABICCIO_CLOSED_DIALOG    = 8529, -- Sorry, but our shop is closed rrright now. Why don't you go to Gustaberg and help the situation out therrre?
        BIN_STEJIHNA_OPEN_DIALOG     = 8530, -- Why don't you buy something from me? You won't regrrret it! I've got all sorts of goods from the Zulkheim region!
        BIN_STEJIHNA_CLOSED_DIALOG   = 8531, -- I'm taking a brrreak from  the saleswoman gig to give dirrrections.  So...through this arrrch is the residential  area.
        TARAIHIPERUNHI_OPEN_DIALOG   = 8532, -- Ooh...do I have some great merchandise for you! Man...these are once-in-a-lifetime offers, so get them while you can.
        TARAIHIPERUNHI_CLOSED_DIALOG = 8533, -- <pant> I am but a poor  merchant. Mate, but you just wait! Strife...one day I'll live the high life. Hey, that's my dream, anyway...
        CATALIA_DIALOG               = 8564, -- While we cannot break our promise to the Windurstians, to ensure justice is served, we would secretly like you to take two shields off of the Yagudo who you meet en route.
        FORINE_DIALOG                = 8565, -- Act according to our convictions while fulfilling our promise with the Tarutaru. This is indeed a fitting course for us, the people of glorious San d'Oria.
        CONQUEST                     = 8933, -- You've earned conquest points!
        APURURU_DIALOG               = 9496, -- There's no way Semih Lafihna will just hand it over for no good reason. Maybe if you try talking with Kupipi...
        EMPYREAL_ARROW_LEARNED       = 9730, -- You have learned the weapon skill Empyreal Arrow!
        TRICK_OR_TREAT               = 9741, -- Trick or treat...
        THANK_YOU_TREAT              = 9742, -- Thank you... And now for your treat...
        HERE_TAKE_THIS               = 9743, -- Here, take this...
        IF_YOU_WEAR_THIS             = 9744, -- If you put this on and walk around, something...unexpected might happen...
        THANK_YOU                    = 9745, -- Thank you...
        NOKKHI_BAD_COUNT             = 9763, -- What kinda smart-alecky baloney is this!? I told you to bring me the same kinda ammunition in complete sets. And don't forget the flowers, neither.
        NOKKHI_GOOD_TRADE            = 9765, -- And here you go! Come back soon, and bring your friends!
        NOKKHI_BAD_ITEM              = 9766, -- I'm real sorry, but there's nothing I can do with those.
        MILLEROVIEUNET_OPEN_DIALOG   = 9991, -- Please have a look at these wonderful products from Qufim Island! You won't regret it!
        MILLEROVIEUNET_CLOSED_DIALOG = 9992, -- Now that I've finally learned the language here, I'd like to start my own business. If I could only find a supplier...
        CLOUD_BAD_COUNT              = 10117, -- Well, don't just stand there like an idiot! I can't do any bundlin' until you fork over a set of 99 tools and <item>! And I ain't doin' no more than seven sets at one time, so don't even try it!
        CLOUD_GOOD_TRADE             = 10121, -- Here, take 'em and scram. And don't say I ain't never did nothin' for you!
        CLOUD_BAD_ITEM               = 10122, -- What the hell is this junk!? Why don't you try bringin' what I asked for before I shove one of my sandals up your...nose!
        CHOCOBO_DIALOG               = 10416, -- Kweh!
        TRRRADE_IN_SPARKS            = 13833, -- You want to trrrade in sparks, do you?
        NOT_ENOUGH_SPARKS            = 13853, -- You do not possess enough sparks of eminence to complete the transaction.
    },
    mob =
    {
    },
    npc =
    {
        HALLOWEEN_SKINS =
        {
            [17764400] = 55, -- Meriri
            [17764401] = 54, -- Kuzah Hpirohpon
            [17764462] = 58, -- Taraihi-Perunhi
            [17764464] = 56, -- Nhobi Zalkia
            [17764465] = 57, -- Millerovieunet
        },
    },
}

return zones[tpz.zone.WINDURST_WOODS]
