public class Main {
    public static void main(String[] args)
    {
        KreatorLucznika k_lucznika = new KreatorLucznika();
        KreatorMiecznika k_miecznika = new KreatorMiecznika();
        KreatorTopornika k_topornika = new KreatorTopornika();

        Ratusz RATUSZ = new Ratusz();

        Postac p1 = RATUSZ.stworzPostac(k_lucznika); // Ratuszowi podajemy tylko który kreator wybieramy
        p1.atakuj();

        System.out.println("");

        Postac p2 = RATUSZ.stworzPostac(k_miecznika); // to co wyżej napisane
        p2.atakuj();

        System.out.println("");

        Postac p3 = RATUSZ.stworzPostac(k_topornika); // to co wyżej napisane
        p3.atakuj();
    }
}

