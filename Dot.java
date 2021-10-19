import java.awt.Color;
import java.awt.*;
import javax.swing.JPanel;

public class Dot{
    private int pointx;
    private int pointy;
    private int pointz;
    private String avg;
    private int pointwidth = 5;
    private int pointheight = 5;
    private Graphics g;
    public Dot(int x, int y, int z){
        pointx = x;
        pointy = y;
        pointz = z;
    }
    public void setgraphic(Graphics g){
        this.g = g;
    }
    public void render(Graphics g){
        g.setColor(Color.BLACK);
        g.fillRect(pointx, pointy, pointwidth, pointheight);
        String temp = ""+ pointz;
        g.drawString(temp, pointx, pointy-5);
    }
}