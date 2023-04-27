
package civitas;
import java.util.ArrayList;


public class Jugador implements Comparable<Jugador> {
    protected static int CasasMax = 4;
    protected static int CasasPorHotel = 4;
    protected Boolean encarcelado;
    protected static int HotelesMax = 4;
    private String nombre;
    private int numCasillaActual;
    protected static float PasoPorSalida = 1000;
    protected static float PrecioLibertad = 200;
    private Boolean puedeComprar;
    private float saldo;
    private static float SaldoInicial = 7500;
    
    private ArrayList<TituloPropiedad> propiedades;
    private Sorpresa salvoconducto;
    
    
    Boolean cancelarHipoteca(int ip){
        Boolean result = false;
        if (!encarcelado){
            if (existeLaPropiedad(ip)){
                TituloPropiedad propiedad = propiedades.get(ip);
                float cantidad = propiedad.getImporteCancelarHipoteca();
                Boolean puedoGastar = puedoGastar(cantidad);
                if (puedoGastar){
                    result = propiedad.cancelarHipoteca(this);
                    if (result){
                        Diario.getInstance().ocurreEvento("El jugador "+nombre+" cancela la hipoteca de la propiedad "+ip);
                    }
                }
            }
        }
        return result;
    }
    
    int cantidadCasasHoteles(){
        int resultado = 0;
        for (int i = 0; i < propiedades.size(); i++){
            resultado = resultado + propiedades.get(i).cantidadCasasHoteles();
        }
        return resultado;
    }
    
    @Override
    public int compareTo(Jugador otro){
        int resultado;
        if (this.getSaldo() < otro.getSaldo()){
            resultado = -1;
        } else if (this.getSaldo() > otro.getSaldo()){
            resultado = 1;
        } else {
            resultado = 0;
        }
        return resultado;
    }
    
    Boolean comprar(TituloPropiedad titulo){
        Boolean result = false;
        if (!encarcelado){
            if (puedeComprar){
                float precio = titulo.getPrecioCompra();
               if (puedoGastar(precio)){
                   result = titulo.comprar(this);
                   if (result){
                       propiedades.add(titulo);
                       Diario.getInstance().ocurreEvento("El jugador "+nombre+" compra la propiedad "+titulo.toString());
                   }
                   puedeComprar = false;
               }
            }
        }
        return result;
    }
    
    Boolean construirCasa(int ip){
        Boolean result = false;
        Boolean puedoEdificarCasa = false;
        if (!encarcelado){
            Boolean existe = existeLaPropiedad(ip);
            if (existe){
                TituloPropiedad propiedad = propiedades.get(ip);
                puedoEdificarCasa = puedoEdificarCasa(propiedad);
                if (puedoEdificarCasa){
                    result = propiedad.construirCasa(this);
                    if (result){
                        Diario.getInstance().ocurreEvento("El jugador "+nombre+" construye casa en la propiedad "+ip);
                    }
                }
            }
        }
        return result;
    }
    
    Boolean construirHotel(int ip){
        Boolean result = false;
        if (!encarcelado){
            if (existeLaPropiedad(ip)){
                TituloPropiedad propiedad = propiedades.get(ip);
                Boolean puedoEdificarHotel = puedoEdificarHotel(propiedad);
                if (puedoEdificarHotel){
                    result = propiedad.construirHotel(this);
                    int casasPorHotel = getCasasPorHotel();
                    propiedad.derruirCasas(casasPorHotel, this);
                }
                Diario.getInstance().ocurreEvento("El jugador "+nombre+" construye hotel en la propiedad "+ip);
            }
        }
        return result;
    }
    
    protected Boolean debeSerEncarcelado(){
        Boolean resultado = false;
        if (!encarcelado){
            if (!tieneSalvoconducto()){
                resultado = true;
            } else {
                resultado = false;
                perderSalvoconducto();
                Diario.getInstance().ocurreEvento("El jugador "+nombre+" se libra de la carcel");
            }
        }
        return resultado;
    }
    
    Boolean enBancarrota(){
        Boolean resultado = false;
        if (getSaldo() < 0){
            resultado = true;
        }
        return resultado;
    }
    
    Boolean encarcelar(int numCasillaCarcel){
        Boolean resultado = false;
        if (debeSerEncarcelado()){
            moverACasilla(numCasillaCarcel);
            encarcelado = true;
            Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha sido encarcelado");
            resultado = encarcelado;
        }
        return resultado;
    }
    
    private Boolean existeLaPropiedad(int ip){
        Boolean resultado = false;
        if (propiedades.get(ip) != null){
            resultado = true;
        }
        return resultado;
    }
    
    private int getCasasMax(){
        return CasasMax;
    }
    
    int getCasasPorHotel(){
        return CasasPorHotel;
    }
    
    private int getHotelesMax(){
        return HotelesMax;
    }
    
    protected String getNombre(){
        return nombre;
    }
    
    int getNumCasillaActual(){
        return numCasillaActual;
    }
    
    private float getPrecioLibertad(){
        return PrecioLibertad;
    }
    
    private float getPremioPasoSalida(){
        return PasoPorSalida;
    }
    
    /*protected*/ public ArrayList<TituloPropiedad> getPropiedades(){
        return propiedades;
    }
    
    Boolean getPuedeComprar(){
        return puedeComprar;
    }
    
    protected float getSaldo(){
        return saldo;
    }
    
    Boolean hipotecar(int ip){
        Boolean result = false;
        if (!encarcelado){
            if (existeLaPropiedad(ip)){
                TituloPropiedad propiedad = propiedades.get(ip);
                result = propiedad.hipotecar(this);
            }
        }
        if (result){
            Diario.getInstance().ocurreEvento("El jugador "+nombre+" hipoteca la propiedad "+ip);
        }
        return result;
    }
    
    public Boolean isEncarcelado(){
        return encarcelado;
    }
    
    Jugador(String nombre){
        encarcelado = false;
        this.nombre = nombre;
        numCasillaActual = 0;
        puedeComprar = true;
        saldo = 7500;
        propiedades = new ArrayList<>();
        salvoconducto = null;
    }
    
    protected Jugador(Jugador otro){
        this.encarcelado = otro.encarcelado;
        this.nombre = otro.nombre;
        this.numCasillaActual = otro.numCasillaActual;
        this.propiedades = otro.propiedades;
        this.puedeComprar = otro.puedeComprar;
        this.saldo = otro.saldo;
        this.salvoconducto = otro.salvoconducto;
    }
    
    Boolean modificarSaldo(float cantidad){
        saldo = saldo + cantidad;
        return true;
    }
    
    Boolean moverACasilla(int numCasilla){
        Boolean resultado = false;
        if (!encarcelado){
            numCasillaActual = numCasilla;
            puedeComprar = true;
            Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha sido movido a la casilla " + numCasilla);
            resultado = true;
        }
        return resultado;
    }
    
    Boolean obtenerSalvoconducto(Sorpresa sorpresa){
        Boolean resultado = false;
        if (!encarcelado){
            salvoconducto = sorpresa;
            resultado = true;
        }
        return resultado;
    }
    
    Boolean paga(float cantidad){
        Boolean resultado = modificarSaldo(cantidad * -1);
        return resultado;
    }
    
    Boolean pagaAlquiler(float cantidad){
        Boolean resultado = false;
        if (!encarcelado){
            resultado = paga(cantidad);
        }
        return resultado;
    }
    
    Boolean pagaImpuesto(float cantidad){
        Boolean resultado = false;
        if (!encarcelado){
            resultado = paga(cantidad);
        }
        return resultado;
    }
    
    Boolean pasaPorSalida(){
        modificarSaldo(getPremioPasoSalida());
        Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha pasado por salida");
        return true;
    }
    
    private void perderSalvoconducto(){
        salvoconducto.usada();
        salvoconducto = null;
    }
    
    Boolean puedeComprarCasilla(){
        puedeComprar = true;
        if (encarcelado){
            puedeComprar = false;
        }
        return puedeComprar;
    }
    
    private Boolean puedeSalirCarcelPagando(){
        Boolean resultado = false;
        if (getSaldo() >= PrecioLibertad){
            resultado = true;
        }
        return resultado;
    }
    
    private Boolean puedoEdificarCasa(TituloPropiedad propiedad){
        Boolean puedoEdificarCasa = false;
        float precio = propiedad.getPrecioEdificar();
        if (puedoGastar(precio) && propiedad.getNumCasas() < getCasasMax()){
            puedoEdificarCasa = true;
        }
        return puedoEdificarCasa;
    }
    
    private Boolean puedoEdificarHotel(TituloPropiedad propiedad){
        /*Boolean resultado = false;
        if (getSaldo() > propiedad.getPrecioEdificar() &&propiedad.getNumCasas() == 4){
            resultado = true;
        }
        return resultado;*/
        Boolean puedoEdificarHotel = false;
        float precio = propiedad.getPrecioEdificar();
        if (puedoGastar(precio)){
            if (propiedad.getNumHoteles() < getHotelesMax()){
                if (propiedad.getNumCasas() >= getCasasPorHotel()){
                    puedoEdificarHotel = true;
                }
            }
        }
        return puedoEdificarHotel;
    }
    
    private Boolean puedoGastar(float precio){
        Boolean resultado = false;
        if (!encarcelado){
            if(saldo >= precio){
                resultado = true;
            }
        }
        return resultado;
    }
    
    Boolean recibe(float cantidad){
        Boolean resultado = false;
        if (!encarcelado){
            resultado = modificarSaldo(cantidad);
        }
        return resultado;
    }
    
    Boolean salirCarcelPagando(){
        Boolean resultado = false;
        if (encarcelado && puedeSalirCarcelPagando()){
            paga(PrecioLibertad);
            encarcelado = false;
            Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha salido de la carcel pagando");
            resultado = true;
        }
        return resultado;
    }
    
    Boolean salirCarcelTirando(){
        Boolean resultado = false;
        if (Dado.getInstance().salgoDeLaCarcel()){
            encarcelado = false;
            Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha salido de la carcel tirando");
            resultado = true;
        }
        return resultado;
    }
    
    Boolean tieneAlgoQueGestionar(){
        Boolean resultado = false;
        if (propiedades != null){
            resultado = true;
        }
        return resultado;
    }
    
    Boolean tieneSalvoconducto(){
        Boolean resultado = false;
        if (salvoconducto != null){
            resultado = true;
        }
        return resultado;
    }
    
    @Override
    public String toString(){
        return "Jugador{ nombre=" + nombre + ", encarcelado=" + encarcelado +  ", numCasillaActual=" + numCasillaActual + ", puedeComprar=" + puedeComprar +
                ", saldo=" + saldo +"}";
    }
    
    Boolean vender(int ip){
        Boolean resultado = false;
        if (!encarcelado && existeLaPropiedad(ip)){
            resultado = propiedades.get(ip).vender(this);
            if(resultado){
                propiedades.remove(ip);
                Diario.getInstance().ocurreEvento("El jugador "+nombre+" ha vendido la propiedad " + propiedades.get(ip).getNombre());
            }
        }
        return resultado;
    }
    
}
