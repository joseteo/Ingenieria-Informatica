package build;

public class Motor {
    private int cv;
    private int cc ;
    private int kilometraje;
    private boolean inyeccion ;
    
    public Motor(int cv, int cc, int kilometraje, boolean inyeccion){
        this.cv = cv;
        this.cc = cc;
        this.kilometraje = kilometraje;
        this.inyeccion = inyeccion ;
    }

    public int getcv(){
        return this.cv;
    }

    public int getcc(){
        return this.cc;
    }
    
    public int getkilometraje(){
        return this.kilometraje;
    }

    public boolean getinyeccion(){
        return this.inyeccion;
    }

}
