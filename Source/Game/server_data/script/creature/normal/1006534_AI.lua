-- 怪物进入战斗触发示警
function c1006534_OnEnterCombat(MapID, InstanceID, CreatureID)
    --得到怪物的当前目标
    local TargetID = cre.GetCreatureCurTargetID(MapID, InstanceID, CreatureID)
    --同步仇恨给范围为8个格子，高度为20的友方怪物
    g_SynCreatureEnmity(MapID, InstanceID, CreatureID, TargetID, 1, 10, 20)
end

aux.RegisterCreatureEvent(1006534, 2, "c1006534_OnEnterCombat")


function c1006534_OnDie(MapID, InstanceID, TargetID, TargetTypeID, RoleID)
	Increase_shili(MapID, InstanceID, RoleID, 1, 2, "jinjieshili")

	--玩家击杀阴煞尸王后播放服务器广播；
	local MsgID = msg.BeginMsgEvent();					--注册广播消息句柄

	local r = math.random(2);	--取随机数
	if ( r==1 ) then
		msg.AddMsgEvent(MsgID,102,100022);
		msg.AddMsgEvent(MsgID,2,RoleID);
	else
		msg.AddMsgEvent(MsgID,102,100023);
		msg.AddMsgEvent(MsgID,2,RoleID);
	end
	msg.DispatchBroadcast(MsgID,3017299919,-1,-1);	--播放巫水场景内广播
	msg.DispatchBroadcast(MsgID,MapID,InstanceID,-1);
end
--注册
aux.RegisterCreatureEvent(1006534, 4, "c1006534_OnDie")




