classdef llnode < handle
    
    properties
        data
    end
    
    properties(SetAccess=private)
        next=llnode.empty;
    end
    
    methods
        
        function node=llnode(Data)
            if nargin>0
                node.data=Data;
            end
        end
        
        function display(head)
            node=head;
            while(~isempty(node))
                disp(node.data);
                node=node.next;
            end
            
        end
        
        function addnode(head,data)
            node=head;
            while(~isempty(node.next))
                node=node.next;
            end
            
            newnode=llnode(data);
            node.next=newnode;
        end
            
        function deletenode(head)
            node=head;
            ahead=node.next;
            
            while(~isempty(ahead.next))
                node=node.next;
                ahead=node.next;
                
            end
            node.next=llnode.empty;
        end
        
        function deletefrompos(position,head);
            node=head;
            for i=2:position-1;
                node=node.next;
            end
            nextnode=node.next;
            aheadnode=nextnode.next;
            node.next= llnode.empty;
            node.next=aheadnode;
        end
           
            
                
        
    end
    
    
     
end
