public class Chodzenie implements Stan {
    public void dzialaj() {
        System.out.println("Gracz idzie przed siebie!");
    }

    public String getNazwaStanu() {
        return "Stan: CHODZENIE";
    }
}