public class CzlonekMafii {
    private String nazwa;

    public CzlonekMafii(String s) {
        nazwa = s;
    }

    public void zbierajHaracz() {
        System.out.println(nazwa + " zbiera haracz.");
    }

    public void zaplanujAkcje() {
        System.out.println(nazwa + " planuje akcje.");
    }

    public void przestanZbieracHaracz() {
        System.out.println(nazwa + " przestaje zbierac haracz.");
    }

    public void przestanPlanowacAkcje() {
        System.out.println(nazwa + " przestaje planowac akcje.");
    }
}