/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica7smm;

import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import static java.lang.Double.max;

/**
 *
 * @author joset
 */
public class Curva extends java.awt.geom.QuadCurve2D.Double{
    
    public Curva(double x1, double y1, double cx, double cy, double x2, double y2){
        super(x1,y1,cx,cy,x2,y2);
    }
    
    public void setLocation(Point2D p){
        double nx = p.getX() - this.getX1();
        double ny = p.getY() - this.getY1();

        Point2D np2 = new Point2D.Double(
                (this.getX2() + nx),
                (this.getY2() + ny));
        Point2D npc = new Point2D.Double(
                (this.getCtrlX() + nx),
                (this.getCtrlY() + ny));
        
        this.setCurve(p, npc, np2);
    }
}
