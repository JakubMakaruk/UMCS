public class Komputer implements CzescKomputera {
    public CzescKomputera [] czesci;

    public Komputer() {
        czesci = new CzescKomputera[3];
        czesci[0] = new Klawiatura();
        czesci[1] = new Myszka();
        czesci[2] = new Monitor();
    }

    public void accept(CzescKomputeraWizytator w) {
        for(int i=0; i<3; i++)
            czesci[i].accept(w);
        w.visit(this);
        System.out.println("Komputer jest gotowy do pracy!");
    }
}

