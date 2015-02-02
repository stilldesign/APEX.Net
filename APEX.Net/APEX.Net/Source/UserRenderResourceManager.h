#pragma once

class UserRenderResourceManager : public NxUserRenderResourceManager
{
	virtual NxUserRenderVertexBuffer*   createVertexBuffer(const NxUserRenderVertexBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release vertex buffer */
	virtual void                        releaseVertexBuffer(NxUserRenderVertexBuffer& buffer)
	{

	}

	/** \brief Create index buffer */
	virtual NxUserRenderIndexBuffer*    createIndexBuffer(const NxUserRenderIndexBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release index buffer */
	virtual void                        releaseIndexBuffer(NxUserRenderIndexBuffer& buffer)
	{

	}

	/** \brief Create bone buffer */
	virtual NxUserRenderBoneBuffer*     createBoneBuffer(const NxUserRenderBoneBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release bone buffer */
	virtual void                        releaseBoneBuffer(NxUserRenderBoneBuffer& buffer)
	{

	}

	/** \brief Create instance buffer */
	virtual NxUserRenderInstanceBuffer* createInstanceBuffer(const NxUserRenderInstanceBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release instance buffer */
	virtual void                        releaseInstanceBuffer(NxUserRenderInstanceBuffer& buffer)
	{

	}

	/** \brief Create sprite buffer */
	virtual NxUserRenderSpriteBuffer*   createSpriteBuffer(const NxUserRenderSpriteBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release sprite buffer */
	virtual void                        releaseSpriteBuffer(NxUserRenderSpriteBuffer& buffer)
	{

	}

	/** \brief Create surface buffer */
	virtual NxUserRenderSurfaceBuffer*  createSurfaceBuffer(const NxUserRenderSurfaceBufferDesc& desc)
	{
		return NULL;
	}
	/** \brief Release surface buffer */
	virtual void                        releaseSurfaceBuffer(NxUserRenderSurfaceBuffer& buffer)
	{

	}

	//virtual NxUserRenderSurfaceBuffer*  createSurfaceBuffer(const NxUserRenderSurfaceBufferDesc& desc)   = 0;
	//virtual void                        releaseSurfaceBuffer(NxUserRenderSurfaceBuffer& buffer)          = 0;

	/** \brief Create resource */
	virtual NxUserRenderResource*       createResource(const NxUserRenderResourceDesc& desc)
	{
		return NULL;
	}

	/**
	releaseResource() should not release any of the included buffer pointers.  Those free methods will be
	called separately by the APEX SDK before (or sometimes after) releasing the NxUserRenderResource.
	*/
	virtual void                        releaseResource(NxUserRenderResource& resource)
	{

	}

	/**
	Get the maximum number of bones supported by a given material. Return 0 for infinite.
	For optimal rendering, do not limit the bone count (return 0 from this function).
	*/
	virtual physx::PxU32                       getMaxBonesForMaterial(void* material)
	{
		return 0;
	}

	/** \brief Get the sprite layout data
	Returns true in case textureDescArray is set.
	In case user is not interested in setting specific layout for sprite PS,
	this function should return false.
	*/
	virtual bool getSpriteLayoutData(physx::PxU32 spriteCount, physx::PxU32 spriteSemanticsBitmap, NxUserRenderSpriteBufferDesc* textureDescArray)
	{
		return false;
	}

	/** \brief Get the instance layout data
	Returns true in case textureDescArray is set.
	In case user is not interested in setting specific layout for sprite PS,
	this function should return false.
	*/
	virtual bool getInstanceLayoutData(physx::PxU32 spriteCount, physx::PxU32 spriteSemanticsBitmap, NxUserRenderInstanceBufferDesc* instanceDescArray)
	{
		return false;
	}
};