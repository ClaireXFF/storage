import java.awt.Color;
import java.awt.Font;
import java.awt.Insets;


import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JTextField;



public class JieMian extends JFrame{
	//��������
	public void CreateJieMian()
	{
		this.setTitle("������");
		this.setLocation(500, 200);
		this.setSize(250,350);
		//this.setResizable(false);
		this.setVisible(true);
		this.setLayout(null);
	}
	
	//�˵�
	public JMenuBar CreateMenu()
	{
		JMenuBar jmb=new JMenuBar();
		JMenu chakan=new JMenu("�鿴<V>");
		JMenu bianji=new JMenu("�༭<E>");
		JMenu bangzhu=new JMenu("����<H>");
		jmb.add(chakan);
		jmb.add(bianji);
		jmb.add(bangzhu);
		return jmb;
	}
	
	//�ı���
	JTextField jtfup=new JTextField();
	JTextField jtf=new JTextField("0");
	public void CreateTxtField()
	{
		jtfup.setBounds(10, 10, 216, 20);
		jtfup.setFont(new Font("΢���ź�", Font.BOLD, 15));
		jtfup.setEditable(false);
		jtfup.setHorizontalAlignment(JTextField.RIGHT);
		jtfup.setBackground(Color.WHITE);
		jtfup.setBorder(null);
		jtfup.setColumns(1);
		
		jtf.setBounds(10,30,216,30);
		jtf.setFont(new Font("΢���ź�", Font.BOLD, 23));
		jtf.setEditable(false);
		jtf.setHorizontalAlignment(JTextField.RIGHT);
		jtf.setBackground(Color.WHITE);
		jtf.setBorder(null);
		jtf.setColumns(2);
	}
	
	//��ť
	String[][] buttons=new String[][]{{"MC","MR","MS","M+","M-"},{"��","CE","C","+/-","��"},{"7","8","9","/","%"},{"4","5","6","*","1/X"},{"1","2","3","-","="},{"0",".","+","0","0"}};
	JButton[][] jbutton=new JButton[6][5];
	public void CreateButtonGroup()
	{
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<5;j++)
			{
				jbutton[i][j]=new JButton();
				jbutton[i][j].setText(buttons[i][j]);
				jbutton[i][j].setMargin(new Insets(0, 0, 0, 0));
		
				if(i==4&&j==4)
					jbutton[i][j].setBounds(186,210,39,65);
				else if (i==5) {
					if(j==0)
						jbutton[i][j].setBounds(10, 245, 83, 30);
					else if (j==1) {
						jbutton[i][j].setBounds(98,245,39,30);
					}
					else if (j==2) {
						jbutton[i][j].setBounds(142,245,39,30);
					}
				}
				else {
					jbutton[i][j].setBounds(10+44*j, 70+35*i, 39, 30);
				}
				
				if(jbutton[i][j].getText().matches("^[0-9]*$")||jbutton[i][j].getText().equals("."))
				{
					jbutton[i][j].setBackground(Color.WHITE);
				}
			}
		}
	}
	
	//����jtf�ı����е����ִ�С
	public void setFontSize()
	{
		if(jtf.getText().length()>10)
            jtf.setFont(new Font("TimesRoman", Font.PLAIN, 15));
        else if(jtf.getText().length()>5)
            jtf.setFont(new Font("TimesRoman", Font.PLAIN, 20));
        else
            jtf.setFont(new Font("TimesRoman", Font.BOLD, 23));
	}
	/**
     * �¼���������һ�����°�ť��Ҫ���ݲ�����ʷ������Ӧ�ķ�Ӧ
     */
    public void listener()
    {
        Listener l = new Listener(this);
        for(int i=0;i<6;i++)
			for(int j=0;j<5;j++)
				if(!((i==5)&&(j==3||j==4)))
					jbutton[i][j].addActionListener(l);
        
    }
    
	public JieMian(){
		CreateJieMian();
		
		this.setJMenuBar(CreateMenu());
		
		CreateTxtField();
		this.add(jtf);
		this.add(jtfup);
		
		CreateButtonGroup();
		for(int i=0;i<6;i++)
			for(int j=0;j<5;j++)
				if(!((i==5)&&(j==3||j==4)))
					this.add(jbutton[i][j]);	
	}
	
	
	public static void main(String[] args) {
		JieMian jm=new JieMian();
		jm.listener();
	}
}


