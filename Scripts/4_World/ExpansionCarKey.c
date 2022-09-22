modded class ExpansionCarKey
{
	override Object GetKeyObject()
	{
		if ( !super.GetKeyObject() )
		{
			EXPrint(ToString() + "::GetKeyObject - looking for car cover");
			foreach ( CarCoverBase cover : CarCoverBase.GetAll() )
			{
				if ( IsPairedTo( cover ) )
				{
					EXPrint(ToString() + "::GetKeyObject - found " + cover);
					m_Vehicle = cover;
					break;
				}
			}
		}

		return m_Vehicle;
	}

	bool IsPairedTo( CarCoverBase cover )
	{
		if ( m_PersistentIDA == 0 || cover.GetPersistentIDA() != m_PersistentIDA )
			return false;

		if ( m_PersistentIDB == 0 || cover.GetPersistentIDB() != m_PersistentIDB )
			return false;

		if ( m_PersistentIDC == 0 || cover.GetPersistentIDC() != m_PersistentIDC )
			return false;

		if ( m_PersistentIDD == 0 || cover.GetPersistentIDD() != m_PersistentIDD )
			return false;

		return true;
	}

	//! This is only here as a work-around because SetMaster in Exp 1.6.2 is currently private
	override void SetMaster(bool state)
	{
		super.SetMaster(state);
	}
}
