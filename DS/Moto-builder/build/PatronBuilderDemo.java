package build;

public class PatronBuilderDemo {
    public static void main(String[] args) {
        Director director = new Director();

        
        MotoBuilder builder = new MotoBuilder();
        director.constructorMotoDeportiva(builder);

        // The final product is often retrieved from a builder object, since
        // Director is not aware and not dependent on concrete builders and
        // products.
        Moto moto = builder.EntregaMoto();
        System.out.println("Moto construida:\n" + moto.toString());


       
    }
}
