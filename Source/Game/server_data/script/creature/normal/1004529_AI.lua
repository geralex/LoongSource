--���ﺰ���ű�

-- �������ս������
function c1004529_OnEnterCombat(MapID, InstanceID, CreatureID)

             cre.MonsterSay(MapID, InstanceID, CreatureID, 10064)
	--�õ�����ĵ�ǰĿ��
    local TargetID = cre.GetCreatureCurTargetID(MapID, InstanceID, CreatureID)
    --ͬ����޸���ΧΪ8�����ӣ��߶�Ϊ20���ѷ�����
    g_SynCreatureEnmity(MapID, InstanceID, CreatureID, TargetID, 1, 10, 20)

end

aux.RegisterCreatureEvent(1004529, 2, "c1004529_OnEnterCombat")

--������������
function c1004529_OnDie(MapID, InstanceID, TargetID, TargetTypeID, RoleID)

	cre.MonsterSay(MapID, InstanceID, TargetID, 10066)
	Increase_shili(MapID, InstanceID, RoleID, 1, 2, "jinjieshili")
end

aux.RegisterCreatureEvent(1004529, 4, "c1004529_OnDie")


