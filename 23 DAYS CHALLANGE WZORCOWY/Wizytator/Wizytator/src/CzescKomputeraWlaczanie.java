public class CzescKomputeraWlaczanie implements CzescKomputeraWizytator {
    public void visit(Klawiatura klawiatura) {
        System.out.println("Wlaczam klawiature.");
    }
    public void visit(Myszka myszka) {
        System.out.println("Wlaczam myszke.");
    }
    public void visit(Monitor monitor) {
        System.out.println("Wlaczam monitor.");
    }
    public void visit(Komputer komputer) {
        System.out.println("Wlaczam komputer.");
    }
}