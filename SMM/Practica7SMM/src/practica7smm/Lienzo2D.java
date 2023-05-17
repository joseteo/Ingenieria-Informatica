/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package practica7smm;

import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Composite;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.geom.*;
import java.awt.image.BufferedImage;
import java.util.*;

/**
 *
 * @author joset
 */
public class Lienzo2D extends javax.swing.JPanel {

    /**
     * Creates new form Lienzo2D
     */
    public Lienzo2D() {
        initComponents();
        
    }
    private List<Shape> vShape = new ArrayList();
    private Color color = Color.black;
    private Forma form = Forma.LINEA;
    Shape forma = new Linea2D.Double(0,0,0,0);
    private boolean relleno, mover = false;
    private String sfuente = "Arial";
    private Ellipse2D clipArea = new Ellipse2D.Float(100,100,500,500);
    private boolean ventanaClipActiva = false;
    private Stroke grosor = new BasicStroke(2.0f);
    private boolean transparente = false;
    private boolean clickNo = false;
    private BufferedImage img;
    private boolean alisar = false;
    private Composite composicion;
    private RenderingHints pistasRenderizado;

    public boolean isMover() {
        return mover;
    }

    public void setMover(boolean mover) {
        this.mover = mover;
    }
    private Point2D puntoInicial = new Point(0,0);
    
    @Override
    public void paint(Graphics g){
        super.paint(g);
        Graphics2D g2d = (Graphics2D)g;
        
        if(img != null)
            g2d.drawImage(img, 0, 0, this);
        if(transparente)
            composicion = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.5f);
        else
            composicion = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1.0f);
        if(alisar)
            pistasRenderizado = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        else
            pistasRenderizado = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_OFF);
        
        g2d.setRenderingHints(pistasRenderizado);
        g2d.setComposite(composicion);
        g2d.setStroke(grosor);
        g2d.setPaint(color);
//        if(ventanaClipActiva)
//            g2d.setClip(clipArea);
        for(Shape s:vShape){
            if (s != null){
                if ((forma != null) && (relleno))
                    g2d.fill(forma);
                g2d.draw(s);
            }
        }
    }
    
    public void setImage(BufferedImage img){
        this.img = img;
        if (img!=null){
            setPreferredSize(new Dimension(img.getWidth(),img.getHeight()));
        }
    }

    public BufferedImage getImage(boolean pintaVector){
        if (pintaVector){
            BufferedImage imgout = new BufferedImage(img.getWidth(), img.getHeight(), img.getType());
            Graphics2D g2dImagen = imgout.createGraphics();

            if (img != null){
                g2dImagen.drawImage(img, 0, 0, this);
            }
            g2dImagen.setPaint(color);
            g2dImagen.setStroke(grosor);
            for (Shape s : vShape){
                if (relleno){
                    g2dImagen.fill(s);
                }
                g2dImagen.draw(s);
            }
            g2dImagen.dispose();

            return imgout;
        }
        else
            return img;
    }
    
    public void setColor(Color color){
        this.color = color;
    }
    
    public Color getColor(){
        return color;
    }
    
    public void setGrosor(Stroke grosor){
        this.grosor = grosor;
    }
    
    public Stroke getGrosor(){
        return grosor;
    }
    
    public void setTransparente(boolean transparente){
        this.transparente = transparente;
    }
    
    public boolean getTransparente(){
        return transparente;
    }
    
    public void setAlisar(boolean alisar){
        this.alisar = alisar;
    }
    
    public boolean getAlisar(){
        return alisar;
    }
    
    public void setForma(Forma form){
        this.form = form;
    }
    
    public Forma getForma(){
        return form;
    }

    public enum Forma{
        LINEA, RECTANGULO, ELIPSE, QUADRATICCURVE, CUBICCURVE, ARC, TRAZOLIBRE, AREA, SMILE
    }
    
    public void setRelleno(boolean relleno){
        this.relleno = relleno;
    }
    
    public boolean getRelleno(){
        return relleno;
    }

    public String getFuente() {
        return sfuente;
    }

    public void setFuente(String sfuente) {
        this.sfuente = sfuente;
    }

    public boolean isVentanaClipActiva() {
        return ventanaClipActiva;
    }

    public void setVentanaClipActiva(boolean ventanaClipActiva) {
        this.ventanaClipActiva = ventanaClipActiva;
    }
    
    
    
    public void nuevo(){
        setForma(Forma.LINEA);
        setRelleno(false);
        setColor(Color.BLACK);
        puntoInicial.setLocation(0, 0);
        forma = new Line2D.Double(0,0,0,0);
        vShape.add(forma);
        this.repaint();
    }
    
    private Shape getFiguraSeleccionada(Point2D p){
        for(Shape s:vShape)
            if(s.contains(p))
                return s;
        return null;
    }
    
/*    public void setLocation(Point2D pos){
        double dx = pos.getX() - this.getX();
        double dy = pos.getY() - this.getY();
        Point2D newp2 = new Point2D.Double(this.getX()+dx,this.getY()+dy);
        this.setLine(pos,newp2);
    }*/
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                formMouseDragged(evt);
            }
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                formMouseMoved(evt);
            }
        });
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                formMousePressed(evt);
            }
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                formMouseReleased(evt);
            }
        });
        setLayout(new java.awt.BorderLayout());
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        if(mover){
            forma = getFiguraSeleccionada(evt.getPoint());
            puntoInicial = evt.getPoint();
        } else {
            if(form == Forma.LINEA){
                forma = new Linea2D(evt.getPoint(), evt.getPoint());
            }
            else if(form == Forma.RECTANGULO){
                forma = new Rectangulo(evt.getPoint().x,evt.getPoint().y,0,0);
            }
            else if(form == Forma.ELIPSE){
                forma = new Elipse(evt.getPoint().x,evt.getPoint().y,0,0);
            }
            else if(form == Forma.QUADRATICCURVE){
                if (!clickNo){
                    forma = new Curva( evt.getPoint().x, evt.getPoint().y,
                            evt.getPoint().x, evt.getPoint().y,
                            0, 0);
                }
                else if (clickNo)
                    ((Curva)forma).setCurve( ((Curva)forma).getP1(), evt.getPoint(), ((Curva)forma).getP2());
            }
            else if(form == Forma.CUBICCURVE){
                forma = new CubicCurve2D.Float( evt.getPoint().x, evt.getPoint().y,
                        0, 0,
                        0, 0,
                        0, 0);                    
            }
            else if(form == Forma.ARC){
                forma = new Arc2D.Double( evt.getPoint().x, evt.getPoint().y,
                     0,
                     0,
                     90, 135,
                     Arc2D.OPEN);           
            }
            else if(form == Forma.TRAZOLIBRE){
                forma = new TrazoLibre(TrazoLibre.WIND_EVEN_ODD);
                ((TrazoLibre)forma).moveTo(evt.getX(), evt.getY());
            }
            else if(form == Forma.AREA){
                    // Crear dos elipses
                    Ellipse2D elipse1 = new Ellipse2D.Double(50, 50, 50, 50);
                    Ellipse2D elipse2 = new Ellipse2D.Double(50, 80, 75, 75);

                    // Crear dos áreas a partir de las elipses
                    Area area1 = new Area(elipse1);
                    Area area2 = new Area(elipse2);

                    // Unir las dos áreas
                    area1.add(area2);
                    forma = area1;
            }
            puntoInicial = evt.getPoint();
            vShape.add(forma);
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if(mover && forma!=null){
            
            double NuevoX = evt.getX() - puntoInicial.getX();
            double NuevoY = evt.getY() - puntoInicial.getY();
            //Código para el caso del rectángulo
            if(forma instanceof Rectangle){
                int nx = evt.getX() - (int)puntoInicial.getX();
                int ny = evt.getY() - (int)puntoInicial.getY();
                ((Rectangle)forma).setLocation(
                        (int)((Rectangle)forma).getLocation().getX() + nx,
                        (int)((Rectangle)forma).getLocation().getY() + ny);
            }
            else if(forma instanceof Elipse){
                ((Elipse)forma).setFrame(
                        ((Elipse)forma).getFrame().getX() + NuevoX, 
                        ((Elipse)forma).getFrame().getY() + NuevoY, 
                        ((Elipse)forma).getWidth(), 
                        ((Elipse)forma).getHeight());
            }
            else if(forma instanceof Linea2D){
                ((Linea2D)forma).setLocation(evt.getPoint());
            }
            else if(forma instanceof Curva){
                Point2D np = new Point2D.Double(((Curva)forma).getX1() + NuevoX, ((Curva)forma).getY1() + NuevoY);
                ((Curva)forma).setLocation(np);
            }
            else if(forma instanceof Smile){
                
            }
            else if(forma instanceof CubicCurve2D){
                double NX2 = ((CubicCurve2D)forma).getX2() - evt.getX();
                double NY2 = ((CubicCurve2D)forma).getY2() - evt.getY();
                
                ((CubicCurve2D)forma).setCurve(
                        NuevoX, 
                        NuevoY, 
                        ((CubicCurve2D)forma).getCtrlX1(),
                        ((CubicCurve2D)forma).getCtrlY1(),
                        ((CubicCurve2D)forma).getCtrlX2(),
                        ((CubicCurve2D)forma).getCtrlY2(),
                        NX2, 
                        NY2);
            }
            else if(forma instanceof Arc2D){               
                ((Arc2D)forma).setArc(
                        NuevoX, 
                        NuevoY, 
                        ((Arc2D)forma).getWidth(),
                        ((Arc2D)forma).getHeight(),
                        90, 135,
                        Arc2D.OPEN);
            }
            else if(forma instanceof TrazoLibre){
                Point2D p = new Point2D.Double( NuevoX, NuevoY);
                ((TrazoLibre)forma).setLocation(p);
            }
            puntoInicial = evt.getPoint();
        }
        else if(forma != null){
            if(forma instanceof Linea2D)
                ((Linea2D)forma).setLine(((Linea2D)forma).getP1(), evt.getPoint());
            else if(forma instanceof Rectangle)
                ((Rectangle)forma).setFrameFromDiagonal(puntoInicial, evt.getPoint());
            else if(forma instanceof Ellipse2D)
                ((Ellipse2D)forma).setFrameFromDiagonal(puntoInicial, evt.getPoint());
            else if(forma instanceof Curva){
                if (!clickNo){
                    ((Curva)forma).setCurve(
                            puntoInicial.getX(), puntoInicial.getY(),
                            puntoInicial.getX(), puntoInicial.getY(),
                            evt.getPoint().x, evt.getPoint().y);
                }else if(clickNo){
                    ((Curva)forma).setCurve(((Curva)forma).getP1(), evt.getPoint(), ((Curva)forma).getP2());
                }
            }
            else if(forma instanceof CubicCurve2D)
                ((CubicCurve2D)forma).setCurve( puntoInicial.getX(), puntoInicial.getY(),
                        ((puntoInicial.getX() + evt.getPoint().x) / 2), ((puntoInicial.getY() + evt.getPoint().y) / 2),
                        ((puntoInicial.getX() + evt.getPoint().x) / 2), ((puntoInicial.getY() + evt.getPoint().y) / 2),
                        evt.getPoint().x, evt.getPoint().y);                    
            else if(forma instanceof Arc2D){
                Rectangle2D rect = new Rectangle2D.Float();
                rect.setFrameFromDiagonal(puntoInicial, evt.getPoint());
                ((Arc2D)forma).setArc(
                        rect, 
                        0, 100,
                        Arc2D.OPEN);        
            }
            else if(forma instanceof TrazoLibre){
                ((TrazoLibre)forma).lineTo((float)evt.getX(), (float)evt.getY());
            }
        }
        this.repaint();
    }//GEN-LAST:event_formMouseDragged

    private void formMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseMoved
        if (ventanaClipActiva) {
            Point corner = evt.getPoint();
            corner.translate((int) clipArea.getWidth() / 2,
                    (int) clipArea.getHeight() / 2);
            clipArea.setFrameFromCenter(evt.getPoint(), corner);
            this.repaint();
        }
    }//GEN-LAST:event_formMouseMoved

    private void formMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseReleased
        if (forma!=null){
            if(forma instanceof Curva){
                if(!clickNo)
                    clickNo = true;
                else if (clickNo)
                    clickNo = false;
            }
        }
    }//GEN-LAST:event_formMouseReleased


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
