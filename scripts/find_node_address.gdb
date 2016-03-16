def find_node_address

set $_head = $arg0
set $i=1

while($i < $arg1)
	
	p $arg0 = $arg0->next
	p $i = $i+1

end

if($arg1 == 0)
        p $arg2 = (List*)0
else
        p $arg2 = $arg0
end

p $arg0 = $_head

end
