/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package practica6smm;

import java.awt.AlphaComposite;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Composite;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.font.TextAttribute;
import java.awt.geom.*;
import java.util.*;
import practica6smm.Linea2D;

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
    Scanner sc = new Scanner(System.in);
    String input = "";
    

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
        
        if(ventanaClipActiva)
            g2d.setClip(clipArea);
        pruebaAtributos(g2d);
        for(Shape s:vShape){
            g2d.fill(s);
        }
    }
    
    public void pruebaAtributos(Graphics2D g2d){
        
        //Recorte
        //Shape clipArea;
        //clipArea = new Ellipse2D.Float(100, 100, 500, 500);
        //g2d.setClip(clipArea);
        
        //g2d.draw(clipArea);

        //Trazo
        Stroke trazo;
        float patronDiscontinuidad[] = {15.0f, 15.0f};
        trazo = new BasicStroke(10.0f,
                BasicStroke.CAP_ROUND,
                BasicStroke.JOIN_MITER, 1.0f,
                patronDiscontinuidad, 0.0f);
        g2d.setStroke(trazo);
        //Pintamos una forma de prueba
        g2d.draw(new Line2D.Float(40, 40, 160, 160));
        
        //Relleno
        Paint rellenoo;
        rellenoo = new Color(255, 100, 0);
        g2d.setPaint(rellenoo);
        g2d.draw(new Rectangle(170, 40, 120, 120));
        g2d.fill(new Rectangle(300, 40, 120, 120));
        
        Point pc1 = new Point(430, 40), pc2 = new Point(550, 160);
        rellenoo = new GradientPaint(pc1, Color.RED, pc2, Color.BLUE);
        g2d.setPaint(rellenoo);
        g2d.fill(new Rectangle(430, 40, 120, 120));
        
        //Composición
        Composite comp;
        comp = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.5f);
        g2d.setComposite(comp);
        g2d.fill(new Rectangle(190, 100, 200, 120));
        
        //Transformación
        Rectangle r = new Rectangle(430, 190, 120, 120);
        g2d.draw(r); //Dibujamos rectángulo sin transformación
        AffineTransform at;
        at = AffineTransform.getRotateInstance(Math.toRadians(45.0),
                r.getCenterX(),
                r.getCenterY());
        g2d.setTransform(at);
        g2d.fill(r);

        at = AffineTransform.getScaleInstance(0.5, 0.5);
        g2d.setTransform(at);
        g2d.draw(r);//Dibujamos rectángulo con transformación
        
        at.setToIdentity();
        at.translate(r.getCenterX(), r.getCenterY());
        at.scale(0.5, 0.5);
        at.translate(-r.getCenterX(), -r.getCenterY());
        g2d.setTransform(at);
        g2d.draw(r);
        
        at.setToIdentity();
        g2d.setTransform(at);
        
        //Fuente
        Font fuente;
        fuente = new Font(sfuente, Font.BOLD | Font.ITALIC, 45);
        g2d.setFont(fuente);
        g2d.drawString("Hola", 30, 220);
        
        Map atributosTexto = fuente.getAttributes();
        atributosTexto.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
        g2d.setFont(new Font(atributosTexto));
        g2d.drawString("mundo", 30, 260);
        
        //Renderización
        RenderingHints render;
        g2d.draw(new Ellipse2D.Float(40, 350, 510, 50)); //Elipse sin antialiasing
        render = new RenderingHints(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setRenderingHints(render);
        g2d.draw(new Ellipse2D.Float(40, 450, 510, 50)); //Elipse con antialiasing
        g2d.drawString("Hola", 30, 170); //Texto con antialiasing
        
        render.put(RenderingHints.KEY_COLOR_RENDERING,
                RenderingHints.VALUE_COLOR_RENDER_QUALITY);
        
        
    }
    
    public void setColor(Color color){
        this.color = color;
    }
    public Color getColor(){
        return color;
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
        });
        setLayout(new java.awt.BorderLayout());
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed
        if(mover)
            forma = getFiguraSeleccionada(evt.getPoint());
        else {
            switch(form){
                case LINEA:
                    forma = new Linea2D(evt.getPoint(), evt.getPoint());
                    break;
                case RECTANGULO:
                    forma = new Rectangle2D.Float(evt.getPoint().x,evt.getPoint().y,0,0);
                    break;
                case ELIPSE:
                    forma = new Ellipse2D.Float(evt.getPoint().x,evt.getPoint().y,0,0);
                    break;
                    case QUADRATICCURVE:
                    forma = new QuadCurve2D.Float( evt.getPoint().x, evt.getPoint().y,
                            0, 0,
                            0, 0);                    
                    break;
                case CUBICCURVE:
                    forma = new CubicCurve2D.Float( evt.getPoint().x, evt.getPoint().y,
                            0, 0,
                            0, 0,
                            0, 0);                    
                    break;
                case ARC:
                    forma = new Arc2D.Double( evt.getPoint().x, evt.getPoint().y,
                         0,
                         0,
                         90, 135,
                         Arc2D.OPEN);           
                    break;
                case TRAZOLIBRE:
                    forma = new Path2D.Float(Path2D.WIND_EVEN_ODD);
                    ((Path2D)forma).moveTo(evt.getPoint().x, evt.getPoint().y);
                    break;
                case AREA:
                    // Crear dos elipses
                    Ellipse2D elipse1 = new Ellipse2D.Double(50, 50, 50, 50);
                    Ellipse2D elipse2 = new Ellipse2D.Double(50, 80, 75, 75);

                    // Crear dos áreas a partir de las elipses
                    Area area1 = new Area(elipse1);
                    Area area2 = new Area(elipse2);

                    // Unir las dos áreas
                    area1.add(area2);
                    forma = area1;
                    break;
            }
            puntoInicial = evt.getPoint();
            vShape.add(forma);
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if(mover){
            //Código para el caso del rectángulo
            if (forma!=null && forma instanceof Rectangle2D){
                double NuevoX = this.getMousePosition().getX() - puntoInicial.getX();
                double NuevoY = this.getMousePosition().getY() - puntoInicial.getY();

                ((Rectangle2D)forma).setFrame(
                        NuevoX, 
                        NuevoY, 
                        ((Rectangle2D)forma).getWidth(), 
                        ((Rectangle2D)forma).getHeight());
            }
            else if (forma!=null && forma instanceof Ellipse2D){
                double NuevoX = this.getMousePosition().getX() - puntoInicial.getX();
                double NuevoY = this.getMousePosition().getY() - puntoInicial.getY();
                
                ((Ellipse2D)forma).setFrame(
                        NuevoX, 
                        NuevoY, 
                        ((Ellipse2D)forma).getWidth(), 
                        ((Ellipse2D)forma).getHeight());
            }
            else if (forma!=null && forma instanceof Linea2D)
                ((Linea2D)forma).setLocation(evt.getPoint());
            
            else if (forma!=null && forma instanceof QuadCurve2D){
                double NuevoX = this.getMousePosition().getX() - puntoInicial.getX();
                double NuevoY = this.getMousePosition().getY() - puntoInicial.getY();
                double NX2 = ((QuadCurve2D)forma).getX2() - this.getMousePosition().getX();
                double NY2 = ((QuadCurve2D)forma).getY2() - this.getMousePosition().getY();
                
                ((QuadCurve2D)forma).setCurve(
                        NuevoX, 
                        NuevoY, 
                        ((QuadCurve2D)forma).getCtrlX(),
                        ((QuadCurve2D)forma).getCtrlY(),
                        NX2, 
                        NY2);
            }
            else if (forma!=null && forma instanceof CubicCurve2D){
                double NuevoX = this.getMousePosition().getX() - puntoInicial.getX();
                double NuevoY = this.getMousePosition().getY() - puntoInicial.getY();
                double NX2 = ((CubicCurve2D)forma).getX2() - this.getMousePosition().getX();
                double NY2 = ((CubicCurve2D)forma).getY2() - this.getMousePosition().getY();
                
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
            else if (forma!=null && forma instanceof Arc2D){
                double NuevoX = this.getMousePosition().getX() - puntoInicial.getX();
                double NuevoY = this.getMousePosition().getY() - puntoInicial.getY();
                
                ((Arc2D)forma).setArc(
                        NuevoX, 
                        NuevoY, 
                        ((Arc2D)forma).getWidth(),
                        ((Arc2D)forma).getHeight(),
                        90, 135,
                        Arc2D.OPEN);
            }
        }
        else {
            switch(form){
                case LINEA:
                    ((Linea2D)forma).setLine(((Linea2D)forma).getP1(), evt.getPoint());
                    break;
                case RECTANGULO:
                    ((Rectangle2D)forma).setFrameFromDiagonal(puntoInicial, evt.getPoint());
                    break;
                case ELIPSE:
                    ((Ellipse2D)forma).setFrameFromDiagonal(puntoInicial, evt.getPoint());
                    break;
                case QUADRATICCURVE:
                    ((QuadCurve2D)forma).setCurve(
                            puntoInicial.getX(), puntoInicial.getY(),
                            ((puntoInicial.getX() + evt.getPoint().x) / 2), ((puntoInicial.getY() + evt.getPoint().y) / 2),
                            evt.getPoint().x, evt.getPoint().y);                    
                    break;
                case CUBICCURVE:
                    ((CubicCurve2D)forma).setCurve( puntoInicial.getX(), puntoInicial.getY(),
                            ((puntoInicial.getX() + evt.getPoint().x) / 2), ((puntoInicial.getY() + evt.getPoint().y) / 2),
                            ((puntoInicial.getX() + evt.getPoint().x) / 2), ((puntoInicial.getY() + evt.getPoint().y) / 2),
                            evt.getPoint().x, evt.getPoint().y);                    
                    break;
                case ARC:
                    Rectangle2D rect = new Rectangle2D.Float();
                    rect.setFrameFromDiagonal(puntoInicial, evt.getPoint());
                    ((Arc2D)forma).setArc(
                            rect, 
                            0, 100,
                            Arc2D.OPEN);        
                    break;
                case TRAZOLIBRE:
                    while(!input.equals("q")){
                        ((Path2D)forma).lineTo(evt.getPoint().x, evt.getPoint().y);
                        System.out.println("Pulas q para terminar el trazo libre.");
                        input = sc.nextLine();
                    };
                    ((Path2D)forma).closePath();
                    break;
                case AREA:
                    break;
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


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
