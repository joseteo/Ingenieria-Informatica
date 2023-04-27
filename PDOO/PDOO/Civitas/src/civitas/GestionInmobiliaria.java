/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

/**
 *
 * @author joseteo
 */
public class GestionInmobiliaria {
    
    private OperacionInmobiliaria operacion;
    private int indice_propiedad;

    public GestionInmobiliaria(OperacionInmobiliaria operacion, int indice_propiedad) {
        this.operacion = operacion;
        this.indice_propiedad = indice_propiedad;
    }
    
    /*private*/ public  OperacionInmobiliaria getOperacion(){
        return this.operacion;
    }
    
    private int getIndicePropiedad(){
        return this.indice_propiedad;
    }
    
}
