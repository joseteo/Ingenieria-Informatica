/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

/**
 *
 * @author aidamartin
 */
public class Civitas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        //1
        int jugadores[] = new int[4];
        for (int i = 0; i < 100; i++){
            jugadores[Dado.getInstance().quienEmpieza(4)]++;
        }
        for (int i = 0; i < jugadores.length; i++){
           System.out.println("El numero de veces que ha salido " + i + " es " + jugadores[i]);
        }
        
        //2
        Dado.getInstance().setDebug(true);
        System.out.println("Con el debug del dado a true la tirada ha salido " + Dado.getInstance().tirar());
        Dado.getInstance().setDebug(false);
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        Dado.getInstance().setDebug(true);
        System.out.println("Con el debug del dado a true la tirada ha salido " + Dado.getInstance().tirar());
        Dado.getInstance().setDebug(false);
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        Dado.getInstance().setDebug(true);
        System.out.println("Con el debug del dado a true la tirada ha salido " + Dado.getInstance().tirar());
        Dado.getInstance().setDebug(false);
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
        System.out.println("Con el debug del dado a false la tirada ha salido " + Dado.getInstance().tirar());
                
        //3
        System.out.println("Dado.getUltimoResultado() = " + Dado.getInstance().getUltimoResultado());
        System.out.println("Dado.salgoDeLaCarcel() = " + Dado.getInstance().salgoDeLaCarcel());
        
        //4
        System.out.println("EstadosJuego " + EstadosJuego.DESPUES_AVANZAR);
        System.out.println("OperacionesJuego " + OperacionesJuego.COMPRAR);
        System.out.println("TipoCasilla " + TipoCasilla.IMPUESTO);
        System.out.println("TipoSorpresa " + TipoSorpresa.PORCASAHOTEL);
        
        //5
        MazoSorpresas mazo = new MazoSorpresas();
        Sorpresa s1 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, 200, "Has ganado el concurso de belleza, ganas 200 euros");
        mazo.alMazo(s1);
        Sorpresa s2 = new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo);
        mazo.alMazo(s2);
        mazo.siguiente();
        mazo.inhabilitarCartaEspecial(s2);
        mazo.habilitarCartaEspecial(s2);
        
        //6
        System.out.println("Diario.getInstance().eventosPendientes() = " + Diario.getInstance().eventosPendientes());
        System.out.println("Diario.getInstance().leerEvento() = " + Diario.getInstance().leerEvento());
        Diario.getInstance().ocurreEvento("TestP1");
        
        //7
        Tablero tablero = new Tablero(8);
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 1", 60, 12, 400, 600, 350))); //casilla 1
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 2", 65, 13, 450, 650, 400))); //casilla 2
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 3", 85, 17, 700, 850, 600))); //casilla 3
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa")); //casilla 4
        tablero.añadeCasilla(new Casilla(tablero.getCarcel(), "Juez")); //casilla 5
        
        //8
        
    }
    
}
