//TechRef PG 19.16(QueryApp4 ka dusare dhang se)

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class QueryApp5 extends Frame
{
	TextField pid;
	TextField pname;
	Button next;
	Panel p;

	static ResultSet result;
	static Connection con;
	static Statement stat;

	public QueryApp5()
	{
		super("The Query Application");
		setLayout(new GridLayout(5,1));
		pid=new TextField(50);
		pname=new TextField(50);
		next=new Button("Next");
		p=new Panel();
		add(new Label ("sRollNo"));
		add(pid);
		add(new Label("sName"));
		add(pname);
		add(p);
		p.add(next);
		x a = new x();
		next.addActionListener(a);
		pack();
		setVisible(true);
	}

	public void showRecord(ResultSet result)
	{
		try
		{
			pid.setText(result.getString(1));
			pname.setText(result.getString(2));
		}
		catch(Exception e)
		{
			System.out.println("No Records Available"+e);
		}
	}

	public static void main(String a[])
	{
		QueryApp5 obj=new QueryApp5();
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		    con = DriverManager.getConnection("jdbc:odbc:pintu","sa","");
		    stat = con.createStatement();
			result = stat.executeQuery("Select sRollNo,sName from student");
			result.next();
		}
		catch(Exception e)
		{
			System.out.println("Error  "+e);
		}
		obj.showRecord(result);
	}
	class x implements ActionListener
	{

		public void actionPerformed(ActionEvent event)
		{
			if(event.getSource()==next)
			{
				try
				{
					//result.next();
					//showRecord(result);
					//result.next();
					if(result.next()==false)
					{
						System.out.println("No Data in the Table");
						JOptionPane.showMessageDialog(null,"No Data Available","TITLE",JOptionPane.INFORMATION_MESSAGE);
					}
				}
				catch(Exception e)
				{
				}
				showRecord(result);
			}
		}
	}
}

