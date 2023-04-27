
package civitas;


public class TituloPropiedad {
    private float alquilerBase;
    private static float factorInteresesHipoteca = 1.1f;
    private float factorRevalorizacion;
    private float hipotecaBase;
    private Boolean hipotecado;
    /*private*/ public String nombre;
    private int numCasas;
    private int numHoteles;
    private float precioCompra;
    private float precioEdificar;
    
    private Jugador propietario;
    
    void actualizaPropietarioPorConversion(Jugador jugador){
        propietario = jugador;
    }
    
    Boolean cancelarHipoteca(Jugador jugador){
        Boolean operacionRealizada = false;
        if (getHipotecado() && esEsteElPropietario(jugador)){
            propietario.paga(getImporteCancelarHipoteca());
            hipotecado = false;
            operacionRealizada = true;
        }
        return operacionRealizada;
    }
    
    int cantidadCasasHoteles(){
        return (getNumCasas() + getNumHoteles());
    }
    
    Boolean comprar(Jugador jugador){
        Boolean resultado = false;
        if (!tienePropietario()){
            actualizaPropietarioPorConversion(jugador);
            //propietario = jugador;
            propietario.paga(getPrecioCompra());
            resultado = true;
        }
        return resultado;
    }
    
    Boolean construirCasa(Jugador jugador){
        Boolean resultado = false;
        if (esEsteElPropietario(jugador)){
            propietario.paga(precioEdificar);
            numCasas++;
            resultado = true;
        }
        return resultado;
    }
    
    Boolean construirHotel(Jugador jugador){
        Boolean resultado = false;
        if (esEsteElPropietario(jugador)){
            propietario.paga(precioEdificar);
            numHoteles++;
            resultado = true;
        }
        return resultado;
    }
    
    Boolean derruirCasas(int n, Jugador jugador){
        Boolean operacionRealizada = false;
        if (esEsteElPropietario(jugador) && getNumCasas() >= n){
            numCasas -= n;
            operacionRealizada = true;
        }
        return operacionRealizada;
    }
    
    /*private*/ protected Boolean esEsteElPropietario(Jugador jugador){
        Boolean resultado = false;
        if (propietario == jugador){
            resultado = true;
        }
        return resultado;
    }
    
    public Boolean getHipotecado(){
        return hipotecado;
    }
    
    float getImporteCancelarHipoteca(){
        return (getImporteHipoteca() * factorInteresesHipoteca);
    }
    
    private float getImporteHipoteca(){
        float cantidadRecibida;
        cantidadRecibida = hipotecaBase * (1 + (numCasas * 0.5f) + (numHoteles * 2.5f));
        return cantidadRecibida;
    }
    
    String getNombre(){
        return nombre;
    }

    int getNumCasas(){
        return numCasas;
    }
    
    int getNumHoteles(){
        return numHoteles;
    }
    
    /*private*/ protected float getPrecioAlquiler(){
        float precioAlquiler;
        precioAlquiler = alquilerBase * (1 + (numCasas * 0.5f) + (numHoteles * 2.5f));
        if (getHipotecado() || propietarioEncarcelado()){
            precioAlquiler = 0;
        }
        return precioAlquiler;
    }
    
    float getPrecioCompra(){
        return precioCompra;
    }
    
    float getPrecioEdificar(){
        return precioEdificar;
    }
    
    private float getPrecioVenta(){
        float precioVenta;
        precioVenta = precioCompra + (numCasas + 5 * numHoteles) * precioEdificar * factorRevalorizacion;
        return precioVenta;
    }
    
    /*package*/ /*protected*/ Jugador getPropietario(){
        return propietario;
    }
    
    Boolean hipotecar(Jugador jugador){
        Boolean operacionRealizada = false;
        if (!hipotecado && esEsteElPropietario(jugador)){
            propietario.recibe(getImporteHipoteca());
            hipotecado = true;
            operacionRealizada = true;
        }
        return operacionRealizada;
    }
    
    private Boolean propietarioEncarcelado(){
        Boolean resultado = false;
        if (tienePropietario()){
            resultado = propietario.isEncarcelado();
        }
        return resultado;
    }
    
    Boolean tienePropietario(){
        Boolean resultado = false;
        if (propietario != null){
            resultado = true;
        }
        return resultado;
    }
    
    TituloPropiedad(String nom, float ab, float fr, float hb, float pc, float pe){
        nombre = nom;
        alquilerBase = ab;
        factorRevalorizacion = fr;
        hipotecaBase = hb;
        precioCompra = pc;
        precioEdificar = pe;
        hipotecado = false;
        numCasas = 0;
        numHoteles = 0;
    }
    
    @Override
    public String toString(){
        return "TituloPropiedad { nombre=" + nombre + ", numero de hoteles=" + numHoteles +
                ", numero de casas=" + numCasas + ", precio de compra=" + precioCompra + 
                ", precioEdificar=" + precioEdificar + ", hipotecada=" + hipotecado + 
                ", alquilerBase=" + alquilerBase + ", factorRevalorizacion=" + factorRevalorizacion + 
                ", hipotecaBase=" + hipotecaBase + " }";
    }
    
    void tramitarAlquiler(Jugador jugador){
        if (tienePropietario() && !esEsteElPropietario(jugador)){
            jugador.pagaAlquiler(getPrecioAlquiler());
            propietario.recibe(getPrecioAlquiler());
        }
    }
    
    Boolean vender(Jugador jugador){
        Boolean resultado = false;
        if (esEsteElPropietario(jugador)){
            propietario.recibe(getPrecioVenta());
            numCasas = 0;
            numHoteles = 0;
            propietario = null;
            resultado = true;
        }
        return resultado;
    }
}