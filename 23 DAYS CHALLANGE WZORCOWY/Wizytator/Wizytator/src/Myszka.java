public class Myszka implements CzescKomputera {
    public void accept(CzescKomputeraWizytator w) {
        w.visit(this);
    }
}

