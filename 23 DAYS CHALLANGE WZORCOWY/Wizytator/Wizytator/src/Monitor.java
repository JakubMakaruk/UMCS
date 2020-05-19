public class Monitor implements CzescKomputera {
    public void accept(CzescKomputeraWizytator w) {
        w.visit(this);
    }
}

