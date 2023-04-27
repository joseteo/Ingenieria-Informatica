/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica7smm;

import java.awt.geom.Line2D;
import java.awt.geom.PathIterator;
import java.awt.geom.Point2D;

/**
 *
 * @author joset
 */
public class TrazoLibre extends java.awt.geom.GeneralPath.Double{
    
    private float x;
    private float y;
    
    public TrazoLibre() {
        super();
    }
    
    public boolean isNear(float x, float y) {
        this.x = x;
        this.y = y;
        
        if (contains(x, y)) {
            return true;
        }
        
        float[] coords = new float[6];
        Line2D segmento = new Line2D.Float();
        float distanciaMinima;
        distanciaMinima = Float.MAX_VALUE;
        
        for (PathIterator i = getPathIterator(null); !i.isDone(); i.next()) {
            int tipo = i.currentSegment(coords);
            
            switch (tipo) {
                case PathIterator.SEG_MOVETO:
                    break;
                case PathIterator.SEG_LINETO:
                    segmento.setLine(coords[0], coords[1], x, y);
                    distanciaMinima = (float) Math.min(distanciaMinima, segmento.ptSegDist(coords[0], coords[1]));
                    break;
                case PathIterator.SEG_QUADTO:
                    // No se consideran curvas de Bézier cuadráticas
                    break;
                case PathIterator.SEG_CUBICTO:
                    // No se consideran curvas de Bézier cúbicas
                    break;
                case PathIterator.SEG_CLOSE:
                    // Se cierra el último segmento con el primer punto
                    segmento.setLine(coords[0], coords[1], x, y);
                    distanciaMinima = (float) Math.min(distanciaMinima, segmento.ptSegDist(coords[0], coords[1]));
                    break;
                default:
                    break;
            }
        }
        
        return distanciaMinima <= 4.0;
    }


    public boolean contains(int x, int y){
        return isNear(x, y);
    }
    
    public void moveTo(int x, int y) {
        double NuevoX = x - this.x;
        double NuevoY = y - this.y;
        Point2D NuevoP = new Point2D.Double(
                this + NuevoX,
                this.getY2() + NuevoY);
        
        super.moveTo(NuevoP.getX(), NuevoP.getY());
    }
}
