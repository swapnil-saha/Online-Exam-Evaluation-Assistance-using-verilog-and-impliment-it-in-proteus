module model(data_1,data_2,data_3,clk,rem_row_value,colm_value_count,prev_colm);

	parameter s=5;
	parameter q=3;

	output reg [0:2]data_1[1:s]; // single column with s rows with 3 bit entity
	output reg [0:2]data_2[1:s]; 
	output reg [0:2]data_3[1:s];

	
	output reg [0:2]rem_row_value[1:q]; // remaining values after prev column
	output reg [0:2]colm_value_count[1:q]; //  column value frequency
	output reg [0:2]prev_colm[1:(q-1)]; // previous colm value store



	input clk;
	integer x=1; // student
	integer y=1; // question
	integer z;
	integer store_z,store_low;

	
	integer enable_1=1;
	integer enable_2=0;
	integer enable_3=0;
	
	

	
	
	
	
	always@(posedge clk)

	begin
		if (enable_1)
			column_1();

		else if(enable_2)
			column_2();

		else if(enable_3)
			column_3();

	end




task column_1 ;

begin
	 data_1[x]<=y;
	if (y==(q))
		y<=1;
	else
		y<=y+1;
		
	if (x==(s))
	begin
		enable_1<=0;
		enable_2<=1;
		x<=1;
	end
	else
		x<=x+1;
end

endtask

task prev_colm_check; // ager column value gula save kore



begin

	for (y=1;y<=q;y=y+1)
	begin
		rem_row_value[y]=y;
	end


		for (y=1;y<=q;y=y+1)
		begin
			for (z=1;z<q;z=z+1)
			begin
				if(prev_colm[z]==y)
				begin
					rem_row_value[y]=0;
				end
			end
		end

end

endtask

task prev_row_el_check; 
input [0:2]org_data[1:s];

begin

	for (y=1;y<=q;y=y+1)
	begin
		colm_value_count[y]=0;
	end

	for (z=1;z<=s;z=z+1)
	begin
	if (z==(x))
	break;
		for (y=1;y<=q;y=y+1)
		begin
			if(org_data[z]==y)
			begin
				colm_value_count[y]=colm_value_count[y]+1;
			end
		end
	end
end

endtask


task after_row_colm_check;

input [0:2]org_data[1:s];
output [0:2]value;


begin
	for(z=1;z<=q;z=z+1)
	begin
		 if ((rem_row_value[z]!=0) && (colm_value_count[z]==0))
		 begin
		 org_data[x]<=z;
		 break;
		 end
	end
	
	if (org_data[x]==0)
	begin
	value_select();
	value=store_z;
	end




end

endtask

task value_select;

begin

	for (z=1;z<=q;z=z+1)
	begin
		if(rem_row_value[z]!=0)
		begin
			store_z=z;
			store_low=colm_value_count[z];
			break;
		end
	end

	for (z=1;z<=q;z=z+1)
	begin
		if((rem_row_value[z]!=0) && (colm_value_count[z]<store_low))
		begin
			store_z=z;
			store_low=colm_value_count[z];
		end
	end

end

endtask


task column_2;

begin
	prev_colm[1]=data_1[x];

	prev_colm_check();
	prev_row_el_check(data_2[1:s]);
	after_row_colm_check(data_2[1:s],data_2[x]);


	if (x==(s))
begin
	enable_2<=0;
	enable_3<=1;
	x<=1;
end
else
	x<=x+1;

end
endtask

task column_3;

begin
	prev_colm[1]=data_1[x];
	prev_colm[2]=data_2[x];
	
	prev_colm_check();
	prev_row_el_check(data_3[1:s]);
	after_row_colm_check(data_3[1:s],data_3[x]);


	if (x==(s))
begin
	enable_3<=0;
	x<=1;
end
else
	x<=x+1;

end
endtask




endmodule 





