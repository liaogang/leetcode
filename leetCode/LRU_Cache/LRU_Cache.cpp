//
//  main.cpp
//  LRU_Cache
//
//  Created by liaogang on 14/10/28.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

#include <map>
#include <list>

using namespace std;

/**
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */





struct Node
{
    int value;
    Node* prev;
    Node *next;
    
    Node(int value):value(value)
    {
    }
};

class DoubleLinkList
{
private:
    int size;
    Node* head;
    Node* tail;
public:
    DoubleLinkList():size(0),head(NULL),tail(NULL)
    {
        
    }
    
    int getSize()
    {
        return size;
    }
    
    void takeToHead(Node* node)
    {
        unlink(node);
        addNode2Head(node);
    }
   
    //unlink and delete node.
    void erase(Node* node)
    {
        delete unlink(node);
    }
    
    Node* unlink(Node* node)
    {
        Node *prev;
        Node *next;
        prev=node->prev;
        next=node->next;
        
        if (prev)
        {
            prev->next=next;
        }
        else
        {
            head=next;
        }
        
        if (next)
        {
            next->prev=prev;
        }
        else
        {
            tail=prev;
        }
        
        
        //delete node;
        size--;
        
        return node;
    }
    
    void addNode2Head(Node *node)
    {
        if (tail == NULL)
        {
            tail = node;
        }
        
        if(head)
        {
            head->prev=node;
            node->next=head;
        }
        

        
        
        head=node;
        size++;
    }
    
    
    Node *getHead()
    {
        return head;
    }
    
    Node *getTail()
    {
        return tail;
    }
    
};











class LRUCache
{
private:
    int capacity;
    DoubleLinkList cache;
    
    map<int, Node*> key_index;
    
public:
    
    
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        int value = -1;
        
        auto finded= key_index.find(key);
        if( finded != key_index.end())
        {
            Node* node = finded->second;
            value = node->value;
            
            
            //bring the last used item to first.
            //so the end item is least recently used item.
            cache.takeToHead(node);
        }
        else
        {
            value = -1;
        }
       
        
        cout<<value<<endl;
        
        return value;
    }
    
    void set(int key, int value)
    {
        //insert
        Node *node = new Node(value);
        
        cache.addNode2Head(node );
        
        key_index[key] = node;
        
        
        
        
        //if size bigger then capacity , them delete the last one.
        if (cache.getSize() > capacity )
        {
            cache.erase(cache.getTail());
        }
    }
    

};






int main(int argc, const char * argv[])
{
    
    //1,[set(2,1),get(2)]
    
    LRUCache c(1);
    c.set(2,1);
    c.get(2);
    
    
    /*
    c.set(33,219);
    c.get(33);
    
    c.set(96,56);
    c.get(115);
    
    c.set(3,280);
    c.get(40);
    
    c.set(85,193);
    c.get(10);
    
    c.set(100,136);
    c.set(81,261);
    c.get(3);
    
    c.set(2,1);
    c.get(2);
    
    
    c.get(3);
    c.get(100);
    c.get(81);
    */
    
    /*
      	105,[set(33,219),get(39),set(96,56),get(129),get(115),get(112),set(3,280),get(40),set(85,193),set(10,10),set(100,136),set(12,66),set(81,261),set(33,58),get(3),set(121,308),set(129,263),get(105),set(104,38),set(65,85),set(3,141),set(29,30),set(80,191),set(52,191),set(8,300),get(136),set(48,261),set(3,193),set(133,193),set(60,183),set(128,148),set(52,176),get(48),set(48,119),set(10,241),get(124),set(130,127),get(61),set(124,27),get(94),set(29,304),set(102,314),get(110),set(23,49),set(134,12),set(55,90),get(14),get(104),set(77,165),set(60,160),get(117),set(58,30),get(54),get(136),get(128),get(131),set(48,114),get(136),set(46,51),set(129,291),set(96,207),get(131),set(89,153),set(120,154),get(111),get(47),get(5),set(114,157),set(57,82),set(113,106),set(74,208),get(56),get(59),get(100),get(132),set(127,202),get(75),set(102,147),get(37),set(53,79),set(119,220),get(47),get(101),get(89),get(20),get(93),get(7),set(48,109),set(71,146),get(43),get(122),set(3,160),get(17),set(80,22),set(80,272),get(75),get(117),set(76,204),set(74,141),set(107,93),set(34,280),set(31,94),get(132),set(71,258),get(61),get(60),set(69,272),get(46),set(42,264),set(87,126),set(107,236),set(131,218),get(79),set(41,71),set(94,111),set(19,124),set(52,70),get(131),get(103),get(81),get(126),set(61,279),set(37,100),get(95),get(54),set(59,136),set(101,219),set(15,248),set(37,91),set(11,174),set(99,65),set(105,249),get(85),set(108,287),set(96,4),get(70),get(24),set(52,206),set(59,306),set(18,296),set(79,95),set(50,131),set(3,161),set(2,229),set(39,183),set(90,225),set(75,23),set(136,280),get(119),set(81,272),get(106),get(106),get(70),set(73,60),set(19,250),set(82,291),set(117,53),set(16,176),get(40),set(7,70),set(135,212),get(59),set(81,201),set(75,305),get(101),set(8,250),get(38),set(28,220),get(21),set(105,266),get(105),get(85),get(55),get(6),set(78,83),get(126),get(102),get(66),set(61,42),set(127,35),set(117,105),get(128),get(102),get(50),set(24,133),set(40,178),set(78,157),set(71,22),get(25),get(82),get(129),set(126,12),get(45),get(40),get(86),get(100),set(30,110),get(49),set(47,185),set(123,101),get(102),get(5),set(40,267),set(48,155),get(108),get(45),set(14,182),set(20,117),set(43,124),get(38),set(77,158),get(111),get(39),set(69,126),set(113,199),set(21,216),get(11),set(117,207),get(30),set(97,84),get(109),set(99,218),get(109),set(113,1),get(62),set(49,89),set(53,311),get(126),set(32,153),set(14,296),get(22),set(14,225),get(49),get(75),set(61,241),get(7),get(6),get(31),set(75,15),get(115),set(84,181),set(125,111),set(105,94),set(48,294),get(106),get(61),set(53,190),get(16),set(12,252),get(28),set(111,122),get(122),set(10,21),get(59),get(72),get(39),get(6),get(126),set(131,177),set(105,253),get(26),set(43,311),get(79),set(91,32),set(7,141),get(38),get(13),set(79,135),get(43),get(94),set(80,182),get(53),set(120,309),set(3,109),get(97),set(9,128),set(114,121),get(56),get(56),set(124,86),set(34,145),get(131),get(78),set(86,21),get(98),set(115,164),set(47,225),get(95),set(89,55),set(26,134),set(8,15),get(11),set(84,276),set(81,67),get(46),get(39),get(92),get(96),set(89,51),set(136,240),get(45),get(27),set(24,209),set(82,145),get(10),set(104,225),set(120,203),set(121,108),set(11,47),get(89),set(80,66),get(16),set(95,101),get(49),get(1),set(77,184),get(27),set(74,313),set(14,118),get(16),get(74),set(88,251),get(124),set(58,101),set(42,81),get(2),set(133,101),get(16),set(1,254),set(25,167),set(53,56),set(73,198),get(48),get(30),get(95),set(90,102),set(92,56),set(2,130),set(52,11),get(9),get(23),set(53,275),set(23,258),get(57),set(136,183),set(75,265),get(85),set(68,274),set(15,255),get(85),set(33,314),set(101,223),set(39,248),set(18,261),set(37,160),get(112),get(65),set(31,240),set(40,295),set(99,231),get(123),set(34,43),get(87),get(80),set(47,279),set(89,299),get(72),set(26,277),set(92,13),set(46,92),set(67,163),set(85,184),get(38),set(35,65),get(70),get(81),set(40,65),get(80),set(80,23),set(76,258),get(69),get(133),set(123,196),set(119,212),set(13,150),set(22,52),set(20,105),set(61,233),get(97),set(128,307),get(85),get(80),get(73),get(30),set(46,44),get(95),set(121,211),set(48,307),get(2),set(27,166),get(50),set(75,41),set(101,105),get(2),set(110,121),set(32,88),set(75,84),set(30,165),set(41,142),set(128,102),set(105,90),set(86,68),set(13,292),set(83,63),set(5,239),get(5),set(68,204),get(127),set(42,137),get(93),set(90,258),set(40,275),set(7,96),get(108),set(104,91),get(63),get(31),set(31,89),get(74),get(81),set(126,148),get(107),set(13,28),set(21,139),get(114),get(5),get(89),get(133),get(20),set(96,135),set(86,100),set(83,75),get(14),set(26,195),get(37),set(1,287),get(79),get(15),get(6),set(68,11),get(52),set(124,80),set(123,277),set(99,281),get(133),get(90),get(45),get(127),set(9,68),set(123,6),set(124,251),set(130,191),set(23,174),set(69,295),get(32),get(37),set(1,64),set(48,116),get(68),set(117,173),set(16,89),get(84),set(28,234),get(129),get(89),get(55),get(83),set(99,264),get(129),get(84),get(14),set(26,274),get(109),get(110),set(96,120),set(128,207),get(12),set(99,233),set(20,305),set(26,24),set(102,32),get(82),set(16,30),set(5,244),get(130),set(109,36),set(134,162),set(13,165),set(45,235),set(112,80),get(6),set(34,98),set(64,250),set(18,237),set(72,21),set(42,105),set(57,108),set(28,229),get(83),set(1,34),set(93,151),set(132,94),set(18,24),set(57,68),set(42,137),get(35),get(80),set(10,288),get(21),get(115),get(131),get(30),get(43),set(97,262),set(55,146),set(81,112),set(2,212),set(5,312),set(82,107),set(14,151),get(77),set(60,42),set(90,309),get(90),set(131,220),get(86),set(106,85),set(85,254),get(14),set(66,262),set(88,243),get(3),set(50,301),set(118,91),get(25),get(105),get(100),get(89),set(111,152),set(65,24),set(41,264),get(117),get(117),set(80,45),get(38),set(11,151),set(126,203),set(128,59),set(6,129),get(91),set(118,2),set(50,164),get(74),get(80),set(48,308),set(109,82),set(3,48),set(123,10),set(59,249),set(128,64),set(41,287),set(52,278),set(98,151),get(12),get(25),set(18,254),set(24,40),get(119),set(66,44),set(61,19),set(80,132),set(62,111),get(80),set(57,188),get(132),get(42),set(18,314),get(48),set(86,138),get(8),set(27,88),set(96,178),set(17,104),set(112,86),get(25),set(129,119),set(93,44),get(115),set(33,36),set(85,190),get(10),set(52,182),set(76,182),get(109),get(118),set(82,301),set(26,158),get(71),set(108,309),set(58,132),set(13,299),set(117,183),get(115),get(89),get(42),set(11,285),set(30,144),get(69),set(31,53),get(21),set(96,162),set(4,227),set(77,120),set(128,136),get(92),set(119,208),set(87,61),set(9,40),set(48,273),get(95),get(35),set(62,267),set(88,161),get(59),get(85),set(131,53),set(114,98),set(90,257),set(108,46),get(54),set(128,223),set(114,168),set(89,203),get(100),get(116),get(14),set(61,104),set(44,161),set(60,132),set(21,310),get(89),set(109,237),get(105),get(32),set(78,101),set(14,71),set(100,47),set(102,33),set(44,29),get(85),get(37),set(68,175),set(116,182),set(42,47),get(9),set(64,37),set(23,32),set(11,124),set(130,189),get(65),set(33,219),set(79,253),get(80),get(16),set(38,18),set(35,67),get(107),get(88),set(37,13),set(71,188),get(35),set(58,268),set(18,260),set(73,23),set(28,102),get(129),get(88),get(65),get(80),set(119,146),get(113),get(62),set(123,138),set(18,1),set(26,208),get(107),get(107),set(76,132),set(121,191),get(4),get(8),get(117),set(11,118),get(43),get(69),get(136),set(66,298),get(25),get(71),get(100),set(26,141),set(53,256),set(111,205),set(126,106),get(43),set(14,39),set(44,41),set(23,230),get(131),get(53),set(104,268),get(30),set(108,48),set(72,45),get(58),get(46),set(128,301),get(71),get(99),get(113),get(121),set(130,122),set(102,5),set(111,51),set(85,229),set(86,157),set(82,283),set(88,52),set(136,105),get(40),get(63),set(114,244),set(29,82),set(83,278),get(131),set(56,33),get(123),get(11),get(119),set(119,1),set(48,52),get(47),set(127,136),set(78,38),set(117,64),set(130,134),set(93,69),set(70,98),get(68),set(4,3),set(92,173),set(114,65),set(7,309),get(31),set(107,271),set(110,69),get(45),set(35,288),get(20),set(38,79),get(46),set(6,123),get(19),set(84,95),get(76),set(71,31),set(72,171),set(35,123),get(32),set(73,85),get(94),get(128),get(28),get(38),get(109),set(85,197),set(10,41),set(71,50),get(128),set(3,55),set(15,9),set(127,215),get(17),get(37),set(111,272),set(79,169),set(86,206),set(40,264),get(134),set(16,207),set(27,127),set(29,48),set(32,122),set(15,35),set(117,36),get(127),get(36),set(72,70),set(49,201),set(89,215),set(134,290),set(77,64),set(26,101),get(99),set(36,96),set(84,129),set(125,264),get(43),get(38),set(24,76),set(45,2),set(32,24),set(84,235),set(16,240),set(17,289),set(49,94),set(90,54),set(88,199),get(23),set(87,19),set(11,19),get(24),get(57),get(4),get(40),set(133,286),set(127,231),get(51),set(52,196),get(27),get(10),get(93),set(115,143),set(62,64),set(59,200),set(75,85),set(7,93),set(117,270),set(116,6),get(32),get(135),set(2,140),set(23,1),set(11,69),set(89,30),set(27,14),get(100),get(61),set(99,41),set(88,12),get(41),set(52,203),get(65),set(62,78),set(104,276),set(105,307),get(7),set(23,123),get(22),set(35,299),get(69),get(11),set(14,112),get(115),get(112),get(108),set(110,165),set(83,165),set(36,260),set(54,73),get(36),set(93,69),get(134),set(125,96),set(74,127),set(110,305),set(92,309),set(87,45),set(31,266),get(10),set(114,206),set(49,141),get(82),set(92,3),set(91,160),get(41),set(60,147),set(36,239),set(23,296),set(134,120),get(6),set(5,283),set(117,68),get(35),get(120),set(44,191),set(121,14),set(118,113),set(84,106),get(23),set(15,240),get(37),set(52,256),set(119,116),set(101,7),set(14,157),set(29,225),set(4,247),set(8,112),set(8,189),set(96,220),get(104),set(72,106),set(23,170),set(67,209),set(70,39),get(18),get(6),get(34),set(121,157),get(16),get(19),set(83,283),set(13,22),set(33,143),set(88,133),get(88),set(5,49),get(38),get(110),get(67),set(23,227),get(68),get(3),set(27,265),get(31),set(13,103),get(116),set(111,282),set(43,71),get(134),set(70,141),get(14),get(119),get(43),get(122),set(38,187),set(8,9),get(63),set(42,140),get(83),get(92),get(106),get(28),set(57,139),set(36,257),set(30,204),get(72),set(105,243),get(16),set(74,25),get(22),set(118,144),get(133),get(71),set(99,21),get(26),get(35),set(89,209),set(106,158),set(76,63),set(112,216),get(128),get(54),set(16,165),set(76,206),set(69,253),get(23),set(54,111),get(80),set(111,72),set(95,217),get(118),set(4,146),get(47),set(108,290),get(43),set(70,8),get(117),get(121),set(42,220),get(48),get(32),set(68,213),set(30,157),set(62,68),get(58),set(125,283),set(132,45),get(85),get(92),set(23,257),get(74),set(18,256),get(90),set(10,158),set(57,34),get(27),get(107)]
     */
    
    
    return 0;
}
