--ʹ�ü��ܺ���

function s2319101_Cast(mapid, instanceid, skillid, ownerid)
     local TypeID = cre.GetCreatureTypeID(mapid,instanceid, ownerid)
     if TypeID == 1005459 then
     local temp = math.random(1,100)
	    if temp>=1 and temp<=20 then
		    --20%���ʺ���
                 cre.MonsterSay(mapid, instanceid, ownerid, 20092)
           end
     end
     return 0
end


--ע��

aux.RegisterSkillEvent(2319101, 1, "s2319101_Cast")