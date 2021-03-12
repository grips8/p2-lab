// zadanie 2
#include <memory>

struct MeleeWeapon
{
    std::string name = "bagnet francuski";
    std::string filler = "llorem ipsum ..";
};

struct Weapon
{
    std::string model = "HK416";
    std::string ammoType = "5.56x45mm NATO";
    std::string countryOfOrigin = "Germany";
};

struct Soldier
{
    std::string name = "John";
    std::string surname = "Smith";
    std::string nationality = "USA";
    std::shared_ptr<Weapon> basicWeapon;
    MeleeWeapon melee;
};

void Implementation ()
{
    Soldier* soldier_1 = new Soldier;
    Soldier* soldier_2 = new Soldier;
    Soldier* soldier_3 = new Soldier;
    Soldier* soldier_4 = new Soldier;

    std::shared_ptr<Weapon> weapon_1(new Weapon);
    std::shared_ptr<Weapon> weapon_2(new Weapon);
    std::shared_ptr<Weapon> weapon_3(new Weapon);

    MeleeWeapon* melee1 = new MeleeWeapon;
    MeleeWeapon* melee2 = new MeleeWeapon;

    (*melee2).name = "maczeta krakowska";


    weapon_2->model = "AN-94";
    weapon_2->ammoType = "5.45x39mm";
    weapon_2->countryOfOrigin = "Russia";

    weapon_3->model = "L85A2";
    weapon_3->ammoType = "5.56x45mm NATO";
    weapon_3->countryOfOrigin = "United Kingdom";


    soldier_2->name = "Hans";
    soldier_2->surname = "Kimmich";
    soldier_2->nationality = "Germany";
    soldier_2->basicWeapon = weapon_1;
    soldier_2->melee = *melee1;

    soldier_3->name = "Anatoly";
    soldier_3->surname = "Karpov";
    soldier_2->nationality = "Russia";
    soldier_3->basicWeapon = weapon_2;
    soldier_3->melee = *melee2;

    soldier_4->name = "Logan";
    soldier_4->surname = "Thomson";
    soldier_2->nationality = "Scotland";
    soldier_4->basicWeapon = weapon_3;
    soldier_4->melee = * melee2;

    (*soldier_1).basicWeapon = weapon_3;
    (*soldier_1).melee = *melee1;
    (*soldier_1).melee.name = "scyzoryk";
    (*(*soldier_1).basicWeapon).model = "L86";

    std::cout << soldier_1->melee.name << std::endl;
    std::cout << (*soldier_2).melee.name << std::endl;

    std::cout << soldier_1->basicWeapon->model << std::endl;
    std::cout << soldier_4->basicWeapon->model << std::endl;

    delete soldier_1;
    delete soldier_2;
    delete soldier_3;
    delete soldier_4;

    delete melee1;
    delete melee2;
}