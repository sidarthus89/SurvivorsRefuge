modded class CarCoverBase
{
	private static ref set< CarCoverBase > m_CCEC_AllCovers = new set< CarCoverBase >;

	protected int m_PersistentIDA;
	protected int m_PersistentIDB;
	protected int m_PersistentIDC;
	protected int m_PersistentIDD;

	protected int m_CurrentSkinIndex;

	protected ExpansionVehicleLockState m_VehicleLockedState;

	void CarCoverBase()
	{
		m_CCEC_AllCovers.Insert( this );
	}
	
	static set< CarCoverBase > GetAll()
	{
		return m_CCEC_AllCovers;
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		super.OnStoreLoad( ctx, version );

		if ( Expansion_Assert_False( ctx.Read( m_PersistentIDA ), "[" + this + "] Failed reading m_PersistentIDA" ) )
			return false;

		if ( Expansion_Assert_False( ctx.Read( m_PersistentIDB ), "[" + this + "] Failed reading m_PersistentIDB" ) )
			return false;

		if ( Expansion_Assert_False( ctx.Read( m_PersistentIDC ), "[" + this + "] Failed reading m_PersistentIDC" ) )
			return false;

		if ( Expansion_Assert_False( ctx.Read( m_PersistentIDD ), "[" + this + "] Failed reading m_PersistentIDD" ) )
			return false;

		int lockState;
		if ( Expansion_Assert_False( ctx.Read( lockState ), "[" + this + "] Failed reading m_VehicleLockedState" ) )
			return false;
		m_VehicleLockedState = lockState;

		ctx.Read( m_CurrentSkinIndex );

		return true;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write( m_PersistentIDA );
		ctx.Write( m_PersistentIDB );
		ctx.Write( m_PersistentIDC );
		ctx.Write( m_PersistentIDD );

		int lockState = m_VehicleLockedState;
		ctx.Write( lockState );

		ctx.Write( m_CurrentSkinIndex );
	}

	override void StoreCarLock(CarScript car)
	{
		m_PersistentIDA = car.GetPersistentIDA();
		m_PersistentIDB = car.GetPersistentIDB();
		m_PersistentIDC = car.GetPersistentIDC();
		m_PersistentIDD = car.GetPersistentIDD();

		m_VehicleLockedState = car.GetLockedState();

		m_CurrentSkinIndex = car.CCEC_GetSkinIndex();

		super.StoreCarLock(car);
	}
	
	override void RestoreCarLock(CarScript car)
	{
		car.SetPersistentIDA( m_PersistentIDA );
		car.SetPersistentIDB( m_PersistentIDB );
		car.SetPersistentIDC( m_PersistentIDC );
		car.SetPersistentIDD( m_PersistentIDD );

		car.SetLockedState( m_VehicleLockedState );

		car.ExpansionSetSkin( m_CurrentSkinIndex );

		super.RestoreCarLock(car);
	}

	int GetPersistentIDA()
	{
		return m_PersistentIDA;
	}

	int GetPersistentIDB()
	{
		return m_PersistentIDB;
	}

	int GetPersistentIDC()
	{
		return m_PersistentIDC;
	}

	int GetPersistentIDD()
	{
		return m_PersistentIDD;
	}
}
