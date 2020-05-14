public class Zatrzymanie implements Stan {
    public void dzialaj() {
        System.out.println("Gracz sie zatrzymal, nic sie nie dzieje.");
    }

    public String getNazwaStanu() {
        return "Stan: ZATRZYMANIE SIE";
    }
}