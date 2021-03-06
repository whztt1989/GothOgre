#ifndef GOTHOGRE_RESOURCE_SYSTEM_APP_BLOCK_H
#define GOTHOGRE_RESOURCE_SYSTEM_APP_BLOCK_H

#include "GothOgre_AppBlock.h"
#include "GothOgre_ResourceLocationScanner.h"
#include "GothOgre_MeshManager.h"
#include "GothOgre_TextureManager.h"
#include "GothOgre_MaterialManager.h"
#include "GothOgre_BspOgreManager.h"
#include "GothOgre_BspManager.h"
#include "GothOgre_SoundOgreManager.h"
#include "GothOgre_SoundManager.h"


namespace GothOgre
{

	class ResourceSystemAppBlock : public AppBlock
	{
	public:
		ResourceSystemAppBlock()
			: mMeshManager(nullptr), mTextureManager(nullptr), mMaterialManager(nullptr),
			  mBspOgreManager(nullptr), mBspManager(nullptr),
			  mSoundOgreManager(nullptr), mSoundManager(nullptr),
			  mResourceLocationScanner(nullptr)
		{
			mMeshManager = new MeshManager;
			mTextureManager = new TextureManager;
			mMaterialManager = new MaterialManager;
			mBspManager = new BspManager;
			mSoundManager = new SoundManager;

			mResourceLocationScanner = new ResourceLocationScanner;
		}

		~ResourceSystemAppBlock()
		{
			if(mBspManager)
				delete mBspManager;

			if(mSoundManager)
				delete mSoundManager;

			if(mMeshManager)
				delete mMeshManager;

			if(mTextureManager)
				delete mTextureManager;

			if(mMaterialManager)
				delete mMaterialManager;

			if(mResourceLocationScanner)
				delete mResourceLocationScanner;
		}

		void initialise()
		{
			String resourcesCfg = CommandLine::getSingleton().getAbsolutePath("resources.cfg");
			mResourceLocationScanner->load(resourcesCfg);

			mBspOgreManager = new BspOgreManager;
			mSoundOgreManager = new SoundOgreManager;
		}

		void shutdown()
		{
			if(mBspOgreManager)
			{
				delete mBspOgreManager;
				mBspOgreManager = nullptr;
			}

			if(mSoundOgreManager)
			{
				delete mSoundOgreManager;
				mSoundOgreManager = nullptr;
			}
		}

	private:
		MeshManager*              mMeshManager;
		TextureManager*           mTextureManager;
		MaterialManager*          mMaterialManager;
		SoundManager*             mSoundManager;
		SoundOgreManager*         mSoundOgreManager;
		BspManager*               mBspManager;
		BspOgreManager*           mBspOgreManager;
		ResourceLocationScanner*  mResourceLocationScanner;
	};

}

#endif // GOTHOGRE_RESOURCE_SYSTEM_APP_BLOCK_H