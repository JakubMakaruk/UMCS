public class Klawiatura implements CzescKomputera {
    public void accept(CzescKomputeraWizytator w) {
        w.visit(this);
    }
}

